#include <stdio.h>

long long f(long long a, long long b) {
    if(!b) return 0;
    if(a > b) a ^= b ^= a ^= b;
    long long c = b / a;
    return a*c + f(a, b-a*c);
}

int main(void) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld", f(a, b));
    return 0;
}