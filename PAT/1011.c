#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int i;
    long long int a[11],b[11],c[11];
    for(i=0;i<n;i++){
        scanf("%d %d %d",&a[i],&b[i],&c[i]);}
    for(i=0;i<n;i++){
        if ((long long) a[i]+b[i]>c[i])
            printf("Case #%d: true\n",i+1);
        else
            printf("Case #%d: false\n",i+1);
    }
    return 0;
}