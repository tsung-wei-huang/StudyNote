# clang-tidy 

clang-tidy is a static analysis tool to perform various checks over a C++ project.

# Install 

On ubuntu machine for example, installing clang-tidy is as easy as running the following command:

```bash
~$ sudo apt-get install clang-tidy
```

The full documentation can be found [here][clang-tidy].

# List Available Checks

Running the tool without any command options will run the default checks.
We can list all available checkers by running the following command:

```bash
~$ clang-tidy --list-checks -checks='*'
```

The names of the checks are very self-explanatory.

# Example 1

Consider the following [example1.cpp](example1.cpp):

```cpp
#include <iostream>

struct Base {
    virtual void reimplementMe(int) {}
};

struct Derived : public Base  {
    virtual void reimplementMe(int) {}
};

int main() {
  return 0;
}
```

Run clang-tidy to perform static analysis with all checks:

```bash
~$ clang-tidy example1.cpp -checks='*' -- -DMACRO_FOR_DEMO=1

/home/twhuang/PhD/Code/StudyNote/clang-tidy/example1.cpp:4:35: warning: all parameters should be named in a function [readability-named-parameter]
    virtual void reimplementMe(int) {}
                                  ^
                                   /*unused*/
/home/twhuang/PhD/Code/StudyNote/clang-tidy/example1.cpp:8:18: warning: prefer using 'override' or (rarely) 'final' instead of 'virtual' [hicpp-use-override]
    virtual void reimplementMe(int) {}
    ~~~~~~~~~~~~~^
                                    override
/home/twhuang/PhD/Code/StudyNote/clang-tidy/example1.cpp:8:35: warning: all parameters should be named in a function [readability-named-parameter]
    virtual void reimplementMe(int) {}
                                  ^
                                   /*unused*/
Suppressed 7716 warnings (7716 in non-user code).
```

clang-tidy has its own checks and can also run static analyzer checks. 
Each check has a name and the checks to run can be chosen using the `-checks=option`.

* * *

[clang-tidy]:         http://clang.llvm.org/extra/index.html




