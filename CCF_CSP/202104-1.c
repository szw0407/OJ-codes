#include<stdio.h>

int main() {
    int n,m,l;
    scanf("%d%d%d", &n,&m,&l);
    int num[2000] = {0};
    int i;
    int tmp;
    for (i=0;i<m*n;i++){
        scanf("%d", &tmp);
        num[tmp]++;
    }
    for (i=0;i<l;i++) printf("%d ", num[i]);
    putchar('\n');
    return 0;
}
