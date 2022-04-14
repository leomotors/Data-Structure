mkdir src/$1
echo "#include \"$1.hpp\"\n\nnamespace LM {\n\n}" > src/$1/$1.cpp
echo "#pragma once\n\nnamespace LM {\n\n}" > src/$1/$1.hpp
echo "#include \"$1.hpp\"\n\n#include \"../shared.hpp\"\n\nint main() {\n\n}" > src/$1/$1.test.cpp
