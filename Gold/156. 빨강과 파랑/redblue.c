#include <stdio.h>
#define MAX 300000

int main(void) {
    int n, r_sum[MAX+1] = {0,}, ans = MAX, l, r, temp;
    char s[MAX+1];
    scanf("%d\n%s", &n, s);
    for(int i = 1; i <= n; i++) r_sum[i] = r_sum[i-1] + (s[i-1] == 'R');
    for(int i = 1; i <= n; i++) {
        l = r_sum[i];
        r = r_sum[n] - r_sum[i];
        if((temp = l + (n-i - r)) < ans) ans = temp;
        if((temp = (i - l) + r) < ans) ans = temp;
    }
    printf("%d", ans);
    return 0;
}