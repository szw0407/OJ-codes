#include<stdio.h>

int main() {
    int n, d;
    long long int tmp[1000][1000] = {0};
    scanf("%d %d", &n, &d);
    int Q[n][d];
    int K[d][n];
    int V[n][d];
    int W[n];
    int i, j, k;
    long long int x;
    for (i = 0;i < n;i++) {
        for (j=0;j<d;j++){
            scanf("%d",&Q[i][j]);
        }
    }
    for (i=0;i<n;i++){
        for (j=0;j<d;j++){
            scanf("%d",&K[j][i]);
        }
    }
    for (i=0;i<n;i++){
        for (j=0;j<d;j++){
            scanf("%d",&V[i][j]);
        }
    }
    for (i=0;i<n;++i) {
        scanf("%d",&W[i]);
    }
    // Directly calculating that is n*n*d, which is too much work for that.
    // Thus we can change the calculation order!
    for (i = 0;i < d;i++) {
        for (j=0;j<d;j++) {
            for (k=0;k<n;k++){
                tmp[i][j] += K[i][k] * V[k][j];
            }
        }
    }
    for (i=0;i<n;i++){
        for (j = 0;j < d;j++) {
            x = 0;
            for (k = 0;k < d;k++) {
                x += Q[i][k] * tmp[k][j];
            }
            x *= W[i];
            printf("%lld ", x);
        }
        putchar('\n');
    }
    return 0;
}