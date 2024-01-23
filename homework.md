# Preparation to do Homework

See [instructions](https://github.com/RU-ECE/DovKrugerCourses/tree/main/setup)

1. Install g++ or clang++
   1. On Windows
      1. msys2 (150MB)
         1. install git
      2. wsl (1GB)
         1. install git
   2. gdb or lldb
2. Install an IDE
   1. CLion + mingw
   2. vscode
3. git
   1. get an account on github

Rubric
0% not handed in OR handed in something meaningless just ot hand in something
25% does not compile, butlooks like an attempt
50% compiles but crashes
100% runs correctly

Your code must compile in g++ 8 or better

Visual Studio is great to use, but do not hand in code that only works in visual studio, it may not compile in g++

DO NOT embed paths in your program:
```cpp
int main() {
    ifstream f("c:\\Dov\\test.dat")
}
```

Your code must follow the instructions given, and any files will load out of the CURRENT DIRECTORY


Assume we will compile, run your code

Homework is preferably done in pairs.