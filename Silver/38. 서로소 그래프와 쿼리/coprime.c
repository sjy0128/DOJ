#include <stdio.h>
#define MAX 1000000

int main(void) {
    int n, q, a;
    char arr[MAX] = {0,};
    scanf("%d %d", &n, &q);
    if(n == 1) arr[0] = -1;
    for(int i = 2; i <= n/2; i++) {
        if(arr[i-1]) continue;
        arr[i-1] = 1;
        for(long long j = (long long)i*i; j <= n; j += i) arr[j-1] = 1;
    }
    while(q--) {
        scanf("%d", &a);
        printf("%d\n", arr[a-1] + 1);
    }
    return 0;
}