#include <stdio.h>
#define MAX 200000

int main(void) {
    int n, i = 0, cnt;
    long long ans = 0;
    char s[MAX];
    scanf("%d\n%s", &n, s);
    do {
        cnt = 1;
        while(s[++i] != '_') cnt++;
        ans += (long long)cnt * cnt;
    } while(i < n-1);
    printf("%lld", ans);
    return 0;
}