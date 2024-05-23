#include<bits/stdc++.h>

using namespace std;

int n, x;

int a[32];
int put[32];
int minsum;
int sum = 0;
void func(int m) {
    int i;
    for (i = m;i >= 0;i--) {
        if (!put[i]) {
            continue;
        }
        if (sum - a[i] < x) {
            continue;
        }
        put[i] = 0;
        sum -= a[i];
        minsum = minsum < sum ? minsum : sum;
        func(i-1);
        put[i] = 1;
        sum += a[i];
    }
    return;
}

int main() {

    scanf("%d %d", &n, &x);
    int i;
    for (i = 0;i < n;i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        put[i] = 1;
    }
    minsum = sum;
    func(n-1);
    printf("%d", minsum);
    return 0;
}