# Dr. Memory Fuzzer Test

Testing Dr. Memory fuzz testing capabilities on Windows using Visual Studio.

See [Dr. Memory's fuzz testing Windows with .exe](https://groups.google.com/d/msg/drmemory-users/0K3ul1U_pKo/6rNG6oRVBgAJ)
thread for detailed discussion.

Source code copied from [fuzzer-test-suite](https://github.com/google/fuzzer-test-suite).

## Requirements

* Dr. Memory 1.11.0+
* Visual Studio 2017 (or earlier versions)

## Build

Open *VS2017 x86 Native Command Prompt*, then

```
nmake /f Makefile.nmake
```

## Run

* Run Dr. Memory in [fuzz testing mode](http://drmemory.org/docs/page_fuzzer.html)

```
drmemory.exe -verbose 32 -fuzz -fuzz_module fuzz_me.exe -fuzz_function DrMemoryFuzzerTest
```

* Optionally, run [symbol query tool](http://drmemory.org/docs/page_symquery.html)
to verify fuzz target function is available

```
symquery.exe -e fuzz_me.exe -v --searchall -s DrMemoryFuzzerTest
```
