mkdir -p build/$1
g++ src/$1/$1.cpp -o build/$1/$1.o -c
g++ src/$1/$1.test.cpp build/$1/$1.o -o build/$1/$1
./build/$1/$1
