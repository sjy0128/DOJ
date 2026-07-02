#include <stdio.h>

int main(void) {
    int n, ai, one = 0, two = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &ai);
        if(ai == 1) one++;
        else two++;
    }
    printf(one >= two && !((one - two) % 3) ? "Yes" : "No");
    return 0;
}