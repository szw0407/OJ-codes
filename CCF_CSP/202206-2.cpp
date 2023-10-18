#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, L, S;
    scanf("%d %d %d", &n, &L, &S);
    int i, j;
    int tmp;
    int x[2005], y[2005];
    for (i=0;i<n;i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    int sm[51][51] = {0};
    int k=0;
    for (i=0;i<=S;i++){
        for (j=0;j<=S;j++) {
            scanf("%d", &tmp);
            sm[S-i][j] = tmp;
            if (tmp) {
                k++;
            }
        }

    }
    int c;
    // the number of trees in small map is k
    for (i=0;i<n;i++){
        // out of range
        if (x[i] +S > L || y[i] + S > L) {
            continue;
        }
        // count trees in the small map
        tmp=0;
        for (j=0;j<n;j++) {
            if (x[j]< x[i] || x[j] > x[i] + S || y[j]<y[i] || y[j] > y[i] + S){
                continue;  // out of range
            }
            tmp++;  // count trees in range
            if (sm[x[j]-x[i]][y[j]-y[i]] == 0) {
                tmp=-1;
                break;
            }
            
        }
        if (tmp==k){
            c++;
        }
    }
    printf("%d\n",c);
    return 0;
}