import chalk from "chalk";
import { exec as execCb } from "node:child_process";
import * as fsSync from "node:fs";
import fs from "node:fs/promises";
import { promisify } from "node:util";

const exec = promisify(execCb);

const buildInfoFileName = ".buildInfo";

type BuildInfo = { [fileName: string]: string };

async function getFileSha(filePath: string) {
    return (await exec(`sha256sum ${filePath}`)).stdout.split(" ")[0];
}
async function getStructSha(struct: string) {
    return (
        await Promise.all(
            ["hpp", "cpp", "test.cpp"].map((ext) =>
                getFileSha(`src/${struct}/${struct}.${ext}`)
            )
        )
    ).join("");
}

async function main() {
    const buildInfo = (
        fsSync.existsSync(buildInfoFileName)
            ? JSON.parse((await fs.readFile(buildInfoFileName)).toString())
            : {}
    ) as BuildInfo;

    const functions = {
        async run() {
            const struct = process.argv[3];
            const structSha = await getStructSha(struct);

            if (
                process.argv.includes("--new") ||
                buildInfo[struct] != structSha
            ) {
                console.log(chalk.cyan(`Building ${struct}`));
                const cpres = await exec(
                    `mkdir -p build && g++ src/${struct}/${struct}.test.cpp src/${struct}/${struct}.cpp -o build/${struct} -Wall -Wextra -std=c++17 -O3 -lm`
                );

                if (cpres.stderr) console.log(chalk.yellow(cpres.stderr));

                buildInfo[struct] = structSha;
                await fs.writeFile(
                    buildInfoFileName,
                    JSON.stringify(buildInfo, null, 4)
                );
            }
            console.log(`Running ${struct}`);
            const res = await exec(`./build/${struct}`);

            console.log(res.stdout);
            if (res.stderr) console.log(chalk.yellow(res.stderr));
        },
    };

    const f = functions[process.argv[2] as keyof typeof functions] as
        | (() => Promise<void>)
        | undefined;

    if (f) await f();
    else console.log(chalk.red(`No such command ${process.argv[2]}`));

    process.exit(f ? 0 : 1);
}

main();
