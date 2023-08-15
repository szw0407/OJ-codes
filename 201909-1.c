#include<stdio.h>

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j;
    int tmp;
    int k;
    int maxk = 0;
    int maxkind = 0;

    unsigned int sum = 0;

    for (i=1;i<=n;i++){
        j=0;
        scanf("%d",&tmp);
        sum += tmp;
        k = 0;
        for (j = 1;j <= m;j++) {
            scanf("%d",&tmp);
            k-=tmp;
            sum += tmp;
        }
        if (maxk<k){
            maxkind = i;
            maxk = k;
        }
    }
    printf("%d %d %d\n",sum,maxkind,maxk);
    return 0;
}