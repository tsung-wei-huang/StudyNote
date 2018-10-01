# clang-tidy 

clang-tidy is a LLVM/clang-based C++ *linter* tool for diagnosing and fixing typical programming errors
including:

+ style convention
+ bugs reported by static analysis
+ interface problems

The full documentation can be found [here][clang-tidy].

# Install 

On ubuntu machine for example, installing clang-tidy is as easy as running the following command:

```bash
~$ sudo apt-get install clang-tidy
```

# List Available Checks

Running the tool without any command options will run the default checks.
We can list all available checkers by running the following command:

```bash
~$ clang-tidy --list-checks -checks='*'
```

The table below shows the list of commonly used checks.

| Check Prefix | Description |
| --- | --- |
| clang-analyzer- | checks via static analysis |
| bugprone- |  checks that target bugprone code construct |
| cppcoreguidelines- | checks related to C++ Core Guidelines |
| google- | hecks related to Google coding conventions |
| llvm- | checks related to the LLVM coding conventions |
| modernize- | checks that advocate usage of modern (C++11/14/17) language constructs |
| performance- | checks that target performance-related issues |
| portability- | checks that target portability-related issues that don't relate to any particular coding style |
| readability- | Checks that target readability-related issues that don't relate to any particular coding style |

# Get Started with clang-tidy

## Basic Usage

Run clang-tidy to perform static analysis with all checks on [example1.cpp](example1.cpp):

```bash
~$ clang-tidy example1.cpp -checks='*' --
```

clang-tidy has its own checks and can also run static analyzer checks. 
Each check has a name and the checks to run can be chosen using the `-checks=option`.

## Switch Analysis with Macro

We can define macro and pass it to clang-tidy to switch the analysis between different
code blocks.
Run clang-tidy with `FOO` defined on [example2.cpp](example2.cpp):



```bash
~$ clang-tidy example2.cpp -checks='*'  -- -DFOO=1
```

Run clang-tidy without `Foo` defined:
 
```bash
~$ clang-tidy example2.cpp -checks='*' -- 
```

## Disable or Enable Specific Checks

The `-checks=option` accepts a list of comma-separated list of positive and negative
(prefix with `-`) globs. 
Positive globs refer to a subset of checks and negative globs remove them.

```bash
~$ clang-tidy example1.cpp -checks="-*,clang-analyzer-*,-clang-analyzer-deadcode.DeadStores"
```

The above command *disable* all checks (`-*`) and enables all `clang-analyzer-*` checks
except `clang-analyzer-deadcode.DeadStores`.
The order of these commands matter.


* * *

[clang-tidy]:         http://clang.llvm.org/extra/index.html




