#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;

char a[1024][1024] = { 2 };

int main(int argc, char* argv[]) {
    int n;
    scanf("%d", &n);
    void pr(int,int,int);
    
    int i;
    int p = 1;
    for (i = 0;i < n;i++) {
        p *= 2;
    }
    int k;
    int j;
    for (i = 0;i < p;i++) {
        for (j = 0;j < p;j++) {
            a[i][j] = 1;
            // printf("%d", 1);
        }
        // printf("\n");
    }
    pr(0, 0, p);
    for (i = 0;i < p;i++) {
        for (j = 0;j < p;j++) {
            printf("%d", a[i][j]);
            if (j != p-1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
void cl(int x, int y,int n) {
    int i, j;
    
    for (i = x;i < n+x;i++) {
        for (j = y;j < n+y;j++) {
            a[i][j] = 0;
            // printf("%d %d\n", i, j);
        }
    }
    return;
}

void pr(int x, int y, int n) {
    void cl(int, int, int);
    // printf("------\n%d %d %d\n--++--\n", x, y,n);
    n = n / 2;
    cl(x,y, n);
    if (n > 1) {
        
        pr(x+n, y, n);
        pr(x, y+n, n);
        pr(x + n, y + n, n);
    }
    else
        return;
}