#include<stdio.h>

#define NUM 650

int main(int argc, char* argv[]){
    int n,l,r,t;
    scanf("%d %d %d %d", &n,&l,&r,&t);
    int i,j;
    int mat[NUM][NUM];
    for (i=0;i<n;++i){
        for (j=0;j<n;++j){
            scanf("%d",&mat[i][j]);
        }
    }
    int sum = 0;
    int cnt = 0;
    int num = 0;
    for (i=0;i<r;++i){
        for (j=0;j<r;++j){
            sum += mat[i][j];
        }
    }
    int k;
    int up;
    int dn;
    int lt,rt;
    int sum1;
    for (i=0;i<n;++i){
        up = i-r;
        dn = i+r;
        if (up > 0){
            for (k=0;k<r;k++){
                sum -= mat[up-1][k];
            }
        } else {
            up = 0;
        }
        if (dn < n){
            for (k=0;k<r;k++){
                sum += mat[dn][k];
            }

        } else {
            dn = n-1;
        }
        sum1 = sum;
        num = dn - up + 1;
        for (j=0;j<n;++j){
            lt = j - r;
            rt = j + r;
            if (lt > 0) {
                for (k=up;k<=dn;k++){
                    sum1 -= mat[k][lt-1];
                }
            } else {
                lt = 0;
            }
            if (rt < n){
                for (k=up;k<=dn;k++){
                    sum1 += mat[k][rt];
                }
            } else {
                rt = n-1;
            }
            if ((double)sum1/(num*(rt - lt + 1)) <= t) 
            cnt +=1;
        }
    }
    printf("%d\n", cnt);
    return 0;
}