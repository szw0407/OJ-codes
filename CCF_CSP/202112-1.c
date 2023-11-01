#include<stdio.h>

int main() {
    int n, N;
    scanf("%d %d",&n, &N);
    int i;
    int ind = 0;
    int tot = 0;
    int a[205] = {0};
    for (i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    for (i=0;i<N;i++) {
        while (a[ind]<=i) {
            ind ++;
            if (ind == n+1){
                tot += n*(N-i);
                printf("%d\n",tot);
                return 0;
            }
        }
        tot += ind -1;
    }
    printf("%d\n", tot);
    return 0;
}