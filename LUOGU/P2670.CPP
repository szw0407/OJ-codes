#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char* argv[]){
    char a[105][105] = { 0 };
    char p[100][100] = { 0 };
    int m, n;
    int i, j;
    char c(char);
    scanf("%d %d\n", &m, &n);
    for (i = 1;i <= m; i++) {
        for (j = 1;j <= n;j++) {
            scanf("%c", &a[i][j]);
            if (a[i][j] == '*') {
                p[i-1][j-1] = '*';
            }
        }
        getchar();
    }
    for (i = 0;i < m;i++) {
        for (j = 0;j < n;j++) {
            if (p[i][j] =='*') {
                printf("*");
                continue;
            }
            p[i][j] = 48 + c(a[i][j]) + c(a[i][j + 1]) + c(a[i][j + 2]) + c(a[i + 1][j]) + c(a[i + 1][j + 2]) + c(a[i + 2][j]) + c(a[i + 2][j + 1]) + c(a[i + 2][j + 2]);
            printf("%c", p[i][j]);
        }
        printf("\n");
    }
    return 0;
}
char c(char t) {
    char tmp=0;
    if (t == '*')
        tmp++;
    return tmp;
}