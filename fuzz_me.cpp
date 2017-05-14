// DrFuzzTest.cpp: simple test of Dr. Memory Fuzzer
//
// Copied from https://github.com/google/fuzzer-test-suite
#include <stdio.h>

bool FuzzMe(unsigned char *data, size_t dataSize)
{
    if (dataSize > 0)
    {
    printf("%s: dataSize=%u, data=%.50s\n", __func__, dataSize, data);
    return dataSize > 0 &&
        data[0] == 'F' &&
        data[1] == 'U' &&
        data[2] == 'Z' &&
        data[3] == 'Z';  // :‑<
    }
    else
    {
        printf("%s: no data\n", __func__);
    }
}

extern "C"
void DrMemoryFuzzerTest(unsigned char *data, size_t dataSize)
{
    FuzzMe(data, dataSize);
}

int main()
{
    unsigned char data[] = {'F', 'U', 'Z', 'Z', 'M', 'E', 0};
    DrMemoryFuzzerTest(data, 3);
    return 0;
}
