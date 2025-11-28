#include<stdio.h>

int main(){
    int a[110];
    int n, minn = 1001;  // should be greater than any a
    scanf("%d", &n);
    for (int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        if (a[i]<minn){
            minn = a[i];
        }
    }
    printf("%d\n", minn);
    return 0;
}
