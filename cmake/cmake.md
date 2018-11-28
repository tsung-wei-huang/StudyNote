# CMake 

CMake is an open-source, cross-platform family of tools designed to build, test and package software.

# Difference between PRIVATE, PUBLIC, and INTERFACE

Say, we are using boost library in a target `A`:

+ `target_include_directories(A PRIVATE ${Boost_INCLUDE_DIRS})` if you only use those Boost headers inside your source files (.cpp) or private header files (.h).
+ `target_include_directories(A INTERFACE ${Boost_INCLUDE_DIRS})` if you don't use those Boost headers inside your source files (therefore, not needing them to compile A). I can't actually think of a real-world example for this.
+ `target_include_directories(A PUBLIC ${Boost_INCLUDE_DIRS})` if you use those Boost headers in your public header files, which are included BOTH in some of A's source files and might also be included in any other client of your A library.
