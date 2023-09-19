#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(int argc, char* argv[]){
    int n;
    scanf("%d", &n);
    int x, y;
    y = 0;
    x = (n - 1) / 2;
    int num[50][50] ={0};
    int i;
    for (i = 1;i <= n*n;i++) {
        num[x][y] = i;
        if (y == 0 && x != n - 1) {
            y = n - 1;
            x++;
        }
        else if (x==n-1 && y!=0)
        {
            x = 0;
            y--;
        }
        else if (y==0 && x==n-1)
        {
            y++;
        }
        else if (num[x+1][y-1] == 0)
        {
            x++;
            y--;
        }
        else {
            y++;
        }



    }
    for (y = 0;y < n;y++) {
        for (x = 0;x < n;x++) {
            printf("%d ", num[x][y]);
        }
        putchar('\n');
    }
    return 0;
}