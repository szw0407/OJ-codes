#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(int argc, char* argv[]){
    int n,m;
    scanf("%d%d", &n, &m);
    int i, j, k;
    int a[1001][10];
    for (i = 1;i <= n;i++) {
        for (j = 0;j < m;j++) {
            scanf("%d", &a[i][j]);
        }
    }
    char flag;
    for (i = 1;i <= n;i++) {
        // flag = 0;
        for (k = 1;k <= n;k++) {
            flag = 0;
            for (j = 0;j < m;j++) {
                if (a[i][j] < a[k][j]) {
                    flag += 1;
                }
            }
            if (flag == m) {
                break;
            }
        }
        if (k == n+1) {
            printf("0\n");
        }
        else {
            printf("%d\n", k);
        }
    }
    return 0;
}   