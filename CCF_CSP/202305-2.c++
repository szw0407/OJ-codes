#include<stdio.h>

long long tmp[1000][1000] = {0};
long long res[1000][20] = {0};

int main() {
    int n,d;
    scanf("%d %d",&n, &d);
    int Q[n][d];
    int K[d][n];
    int V[n][d];
    int W[n];
    int i,j,k;
    for (i=0;i<n;i++){
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
    for (i=0;i<n;i++){
        for (j=0;j<n;j++) {
            for (k=0;k<d;k++){
                tmp[i][j] += Q[i][k] * K[k][j];
            }
        }
    }
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            tmp[i][j] *= W[i];
        }
    }
    for (i=0;i<n;i++){
        for (j=0;j<d;j++) {
            for (k=0;k<n;k++){
                res[i][j] += tmp[i][k] * V[k][j];
            }
        }
    }
    for (i=0;i<n;i++){
        for (j=0;j<d;j++) {
            printf("%d",res[i][j]);
            if (j< d-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}