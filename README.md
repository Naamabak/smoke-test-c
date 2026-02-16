# docgen-smoke-plus

Repo to test Doxygen auto-comment insertion for C/C++.

## Build (C part)
cc -Iinclude -o c_demo src/api.c src/callbacks.c

## Build (C++ part)
c++ -Iinclude -std=c++17 -o cpp_demo src/cxx_api.cpp
