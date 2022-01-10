mkdir src/$1
echo "#include \"$1.hpp\"" > src/$1/$1.cpp
echo "#pragma once" > src/$1/$1.hpp
echo "#include \"$1.hpp\"" > src/$1/$1.test.cpp
