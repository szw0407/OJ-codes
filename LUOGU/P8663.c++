#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;

int main() {
    int n, K;
    scanf("%d%d", &n, &K);
    int tmp;
    int i;
    long long int sum=0;
    long long int maxsum = 0;
    int j = 0;
    long long int moded[K][3] = { -9999999 };
    int k;
    for (i = 0;i < n;i++) {
        scanf("%d", &tmp);
        if (tmp > moded[tmp % K][0]) {
            
            moded[tmp % K][2] = moded[tmp % K][1];
            moded[tmp % K][1] = moded[tmp % K][0];
            moded[tmp % K][0] = tmp;
        }
        else if (tmp > moded[tmp%K][1])
        {
            moded[tmp % K][2] = moded[tmp % K][1];
            moded[tmp % K][1] = tmp;
        }
        else if (tmp>moded[tmp%K][2])
        {
            moded[tmp % K][2] = tmp;
        }
        

    }
    for (i = 0;i < K;i++) {
        for (j = i;j < K ;j++) {
            if (i == 0 && j == 0) k = 0;
            else if (i + j <= K) k = K - i - j;
            else k = 2 * K - i - j;
            if (i == j && j == k) {
                sum = moded[i][0] + moded[j][1] + moded[k][2];
            }
            else if (i==j)
            {
                sum = moded[i][0] + moded[j][1] + moded[k][0];
            }
            else if (i==k)
            {
                sum = moded[i][0] + moded[j][0] + moded[k][1];
            }
            else if (j==k) {
                sum = moded[i][0] + moded[j][0] + moded[k][1];
            }
            else {
                sum = moded[i][0] + moded[j][0] + moded[k][0];
            }
            if (sum > maxsum) {
                maxsum = sum;
            }
        }
    }    
    printf("%lld", maxsum);
    return 0;
}
