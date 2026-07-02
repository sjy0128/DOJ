#include <stdio.h>
#define MAX_LEN 200000

int main(void) {
    int n, k;
    long long a[MAX_LEN] = {0,}, cur, ans = 0;
    scanf("%d %d", &n, &k);
    if(k > 0) {
        for(int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
    } else {
        k = -k;
        for(int i = n-1; i >= 0; i--) {
            scanf("%lld", &a[i]);
            a[i] *= -1;
        }
    }
    for(int i = 1; i < n; i++) {
        if(a[i] > a[i-1]) continue;
        cur = (a[i-1] - a[i]) / k + 1;
        a[i] += cur * k;
        ans += cur;
    }
    printf("%lld", ans);
    return 0;
}