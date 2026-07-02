#include <stdio.h>
#define MAX 1000

typedef struct { short x, y; } Pos;
Pos qu[MAX*MAX];
int f = 0, r = 0;

int main(void) {
    short n, m;
    short dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    int cnt, ans = 0;
    Pos cur;
    char b[MAX][MAX+1];
    scanf("%hd %hd", &n, &m);
    for(short i = 0; i < n; i++) {
        scanf("%s", b[i]);
        for(short j = 0; j < m; j++) {
            if(b[i][j] == 'S') qu[r++] = (Pos){i, j};
        }
    }
    while(f < r) {
        ans++;
        cnt = r - f;
        while(cnt--) {
            cur = qu[f++];
            for(short d = 0; d < 4; d++) {
                for(short x = cur.x, y = cur.y; b[x][y] != '#'; x += dx[d], y += dy[d]) {
                    if(b[x][y] == 'T') {
                        printf("%d", ans);
                        return 0;
                    }
                    if(b[x][y] != 'S') {
                        b[x][y] = 'S';
                        qu[r++] = (Pos){x, y};
                    }
                }
            }
        }
    }
    printf("%d", -1);
    return 0;
}