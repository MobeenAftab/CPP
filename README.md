# C++

My repository containing various code snippets in C++.

Folders divide C++ source files and grouped relevant sections together.

# Compiling C++

## Linux

To run, compile and produce a C output file type the following in CLI:

`gcc "FILENAME.c" -o "FILEOUT"`

gcc = source file to compile -o = compiled source output name

Run the output file by typing: `./ "FILENAME" or make "FILENAME"` Where "FILENAME" is the same name as the compiled output source file.

## Windows

To run, compile and produce a C output file type the following in VS developer command prompt:

`'cl /EHsc "FILENAME.c" -o "FILEOUT"`

cl = source file to compile -o = compiled source output name

/EHsc = The /EHsc command-line option instructs the compiler to enable C++ exception handling. For more information, see [/EH (Exception Handling Model)](https://docs.microsoft.com/en-gb/cpp/build/reference/eh-exception-handling-model).

To compile a programme with multiple source files:

`cl /W4 /EHsc file1.cpp file2.cpp file3.cpp /link /out:program1.exe`

/w4 = catch more programming mistakes automatically by using warning labels.

/link = change the name to program1.exe, add an /out linker option.

See more optional C++ building references [here] where you can apply to build, optimize, debug, and analyze your code(https://docs.microsoft.com/en-gb/cpp/build/reference/c-cpp-building-reference).

Run the output file by typing: `"FILENAME"` Where "FILENAME" is the same name as the compiled output source file.

[Walkthrough: Compile a C++ program on the command line](https://docs.microsoft.com/en-gb/cpp/build/walkthrough-compiling-a-native-cpp-program-on-the-command-line)

[Build C/C++ code on the command line](https://docs.microsoft.com/en-gb/cpp/build/building-on-the-command-line)

## Makefile

Both Linux and Windows can batch compile, clean and process C source files by running a Makefile script to call the various individual commands. Use flags to control the process of compiling source files.

[Windows NMAKE Reference](https://msdn.microsoft.com/en-us/library/dd9y37ha.aspx)
