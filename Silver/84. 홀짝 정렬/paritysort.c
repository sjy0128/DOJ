#include <stdio.h>
#include <stdlib.h>
#define MAX 200000

void sort(int *a, int n);
void sort_sub(int *a, int *t, int s, int e);

int main(void) {
    int n, num, oa[MAX/2], ea[MAX/2], cur, prev = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &num);
        if(i % 2) oa[i/2] = num;
        else ea[i/2-1] = num;
    }
    sort(oa, (n+1)/2);
    sort(ea, n/2);
    for(int i = 1; i <= n; i++) {
        cur = i % 2 ? oa[i/2] : ea[i/2-1];
        if(cur < prev) {
            printf("NO");
            return 0;
        }
        prev = cur;
    }
    printf("YES");
    return 0;
}

void sort(int *a, int n) {
    int *t = (int *)malloc(sizeof(int) * n);
    sort_sub(a, t, 0, n-1);
    free(t);
}

void sort_sub(int *a, int *t, int s, int e) {
    if(s >= e) return;
    int m = (s+e)/2;
    int i = s, j = m+1, k = s;
    sort_sub(a, t, s, m);
    sort_sub(a, t, m+1, e);
    while(i <= m && j <= e) t[k++] = a[a[i] <= a[j] ? i++ : j++];
    while(i <= m) t[k++] = a[i++];
    while(j <= e) t[k++] = a[j++];
    for(i = s; i <= e; i++) a[i] = t[i];
}