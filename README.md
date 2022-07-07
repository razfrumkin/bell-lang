# Bell

Bell is a programming language that transpiles to C and intends to run on macOS. Bell is a personal project.

## Using [CMake](https://cmake.org/install/) to Compile the Bell Compiler on macOS

Configure:
```bash
cmake -S . -B <build-directory>
```

Build:
```bash
cmake --build <build-directory>
```

Run:
```bash
./<build-directory>/bell
```