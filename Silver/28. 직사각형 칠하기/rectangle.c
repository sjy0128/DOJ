#include <stdio.h>

int main(void) {
    int w, h, d;
    scanf("%d %d %d", &w, &h, &d);
    if(d*2 >= w || d*2 >= h) printf("%lld", (long long)w*h);
    else printf("%lld", (long long)w*d*2 + (long long)(h-d*2)*d*2);
    return 0;
}