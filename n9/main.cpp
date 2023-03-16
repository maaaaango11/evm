#include <iostream>
const uint64_t N = 100000000 * 2;
const uint64_t RUNS_COUNT = 3;
static inline uint64_t rdtsc()
{
    uint64_t hi, lo;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return lo | (hi << 32ull);
}
static inline uint64_t cycleArray(unsigned int const *arr)
{
    volatile size_t i;
    volatile size_t k;
    volatile size_t j;
    volatile uint64_t t1, t2;
    uint64_t tmin = ULLONG_MAX;
    for(j = 0; j < RUNS_COUNT; j++)
    {
        t1 = rdtsc();
        for(k = 0, i = 0; i < N; i++)
        k = arr[k];
        t2 = rdtsc();

        if(tmin > t2 - t1)
            tmin = t2 - t1;
    }
    return tmin;
}
void initArr(unsigned int *arr, unsigned int fragments, size_t offset, size_t size)
{
    size_t i = 0;
    size_t j = 1;
    for(i = 0; i < size; i++)
    {
        for(j = 1; j < fragments; j++)
        arr[i + (j - 1) * offset] = i + j * offset;
        arr[i + (j - 1) * offset] = i + 1;
    }
    arr[i - 1 + (j - 1) * offset] = 0;
}
void runArr(unsigned int *arr, unsigned int fragments, int offset, int size)
{
    initArr(arr, fragments, offset, size);
    printf("fragments: %u\t tacts: %llu\n", fragments, cycleArray(arr) / N);
}
int main()
{
    auto *array = (unsigned int *) malloc(N * sizeof(unsigned int));
    if(!array)
        return 1;
    for(int n = 1; n <= 32; n++)
    runArr(array, n, 32* 1024 * 1024 / sizeof(int), 3* 1024 * 1024 / sizeof(int));
    free(array);
    return 0;
}