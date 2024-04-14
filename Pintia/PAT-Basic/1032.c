#include<stdio.h>

int main(){
    int n,i;
    scanf("%d",&n);
    int num,s;
    int tot[10003]={0};
    int res;
    for (i=0; i<n;i++){
        scanf("%d %d",&num,&s);
        tot[n]+=s;
    }
    int max=tot[1];
    res=1;
    for (i=2;i<n;i++){
        if (tot[i]>max){
            max=tot[i];
            res=i;
        }
    }
    printf("%d %d",res,max);
    return 0;
}