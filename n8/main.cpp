#include <iostream>
#include <cmath>
#include <set>
#include <cstdlib>
#include <windows.h>
#include <ctime>
using namespace std;
void initStraight(unsigned int *arr, unsigned int n)
{
    for(unsigned int i = 0; i < n - 1; ++i)
    arr[i] = i + 1;
    arr[n - 1] = 0;
}
void initBack(unsigned int *arr, unsigned int n)
{
    for(unsigned int i = n - 1; i > 0; --i)
    arr[i] = i - 1;
    arr[0] = n - 1;
}
void initRandom(unsigned int *arr, unsigned int n)
{
    srand((unsigned int)time(NULL)/2);
    set<unsigned int> set;
    for(unsigned int i = 0; i < n; ++i)
    set.insert(i);
    unsigned int index = rand() % set.size();
    unsigned int prev = *next(set.begin(), index);
    unsigned int start = prev;
    for(; set.size() > 1;)
    {
        set.erase(next(set.begin(), index));
        index = rand() % set.size();
        arr[prev] = *next(set.begin(), index);
        prev = *next(set.begin(), index);
    }
    arr[*set.begin()] = start;

}
unsigned int m = 0;
void run(const unsigned int *arr, unsigned int n, unsigned int k)
{
for(unsigned int j = 0; j < n * k; ++j)
m = arr[m];
}
//union ticks
//{
//    long long t64;
//    struct s32
//    {
//        long th, tl;
//    } t32;
//} start0, end0;
int main(int argc, char **argv) {
    int mode = 1;//atoi(argv[1]);
    int nMax = 14;
    int nMin;
    for(nMin = 0; nMin<=nMax; nMin++){
        unsigned int n = 256*(int)pow(2, nMin);
        unsigned int k = 20;//atoi(argv[2]);
        auto *array = (unsigned int *) malloc(n * sizeof(unsigned int));
        switch (mode){
            case 0:
                initRandom(array, n);
                break;
            case 1:
                initStraight(array, n);
                break;
            case 2:
                initBack(array, n);
                break;
        }
        run(array, n, 1);
        //asm("rdtsc\n ":"=a"(start0.t32.th), "=d"(start0.t32.tl));
        FILETIME createTime;
        FILETIME exitTime;
        FILETIME kernelTime;
        FILETIME userTime;
        SYSTEMTIME userSystemTimeEnd;
        SYSTEMTIME userSystemTimeStart;
        if ( GetProcessTimes( GetCurrentProcess(),
                              &createTime, &exitTime, &kernelTime, &userTime ) != -1 )
        {

            FileTimeToSystemTime( &userTime, &userSystemTimeStart );
        }
        run(array, n, k);
        if ( GetProcessTimes( GetCurrentProcess(),
                              &createTime, &exitTime, &kernelTime, &userTime ) != -1 )
        {

            FileTimeToSystemTime( &userTime, &userSystemTimeEnd );
        }
        //asm("rdtsc\n ":"=a"(end0.t32.th), "=d"(end0.t32.tl));
        //unsigned long long fullTime = end0.t64 - start0.t64;
        cout <<"size: " << pow(2, nMin) << " ticks: " << (((double)userSystemTimeEnd.wSecond - (double)userSystemTimeStart.wSecond)+(((double)userSystemTimeEnd.wMilliseconds/1000.0) - (double)userSystemTimeStart.wMilliseconds/1000.0)) <<endl;
        free(array);
    }
    return 0;
}