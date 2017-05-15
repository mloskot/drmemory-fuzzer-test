# Dr. Memory Fuzzer Test

[![Travis CI](https://travis-ci.org/mloskot/drmemory-fuzzer-test.svg?branch=master)](https://travis-ci.org/mloskot/drmemory-fuzzer-test)
[![AppVeyor](https://ci.appveyor.com/api/projects/status/yif1aupyhskg80wa/branch/master?svg=true)](https://ci.appveyor.com/project/mloskot/drmemory-fuzzer-test/branch/master)

Testing Dr. Memory fuzz testing capabilities on Windows and Linux.

See [Dr. Memory's fuzz testing Windows with .exe](https://groups.google.com/d/msg/drmemory-users/0K3ul1U_pKo/6rNG6oRVBgAJ)
thread for detailed discussion.

Source code copied from [fuzzer-test-suite](https://github.com/google/fuzzer-test-suite).

## Requirements

* Dr. Memory 1.11.0+
* C/C++ compiler

## Build

* Linux

```
nmake -f Makefile
```

* Windows with Visual C++

```
nmake /f Makefile.nmake
```

## Run

* Run Dr. Memory in [fuzz testing mode](http://drmemory.org/docs/page_fuzzer.html)

```
drmemory -verbose 32 -fuzz -fuzz_function DrMemoryFuzzerTest -- fuzz_me
```

* Optionally, run [symbol query tool](http://drmemory.org/docs/page_symquery.html)
to verify fuzz target function is available

```
symquery.exe -e fuzz_me.exe -v --searchall -s DrMemoryFuzzerTest
```
