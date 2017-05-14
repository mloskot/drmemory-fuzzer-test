// DrFuzzTest.cpp: simple test of Dr. Memory Fuzzer
//
// Copied from https://github.com/google/fuzzer-test-suite
#include <stdio.h>

bool FuzzMe(unsigned char *data, size_t dataSize)
{
    printf("%s: dataSize=%u, data=%.50s\n", __func__, dataSize, data);
    return dataSize > 0 &&
        data[0] == 'F' &&
        data[1] == 'U' &&
        data[2] == 'Z' &&
        data[3] == 'Z';  // :‑<
}

extern "C"
void DrMemoryFuzzerTest(unsigned char *data, size_t dataSize)
{
    FuzzMe(data, dataSize);
}

int main()
{
    DrMemoryFuzzerTest(NULL, 0);
    return 0;
}
