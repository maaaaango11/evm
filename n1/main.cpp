#include <iostream>
#include <math.h>

long double fact(long double n){
    if(n == 1) return 1;
    return n*fact(n-1);
}

long double s_i_n(long double x, int n){
    long double r = 0;
    for(int i = 1; i<=n; i++){
        //if(fact(2*i-1) == NAN) return 0;
        long double a = fact(2*i-1);
        r+=(long double)(pow(-1,i-1)*pow(x,2*i-1)/(a));
        std::cout <<  a << std::endl;
    }
    return r;
}
int main(int argc, char* argv[]) {
    //int n = atof(argv[2]);
    //unsigned long long g = atof(argv[1]);
    printf("%Lf\n", s_i_n(1.042, 9000));
}
