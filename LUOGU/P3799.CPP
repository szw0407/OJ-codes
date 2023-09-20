#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char* argv[]){
    int n;
    scanf("%d", &n);
    long long int a[5003] = {0};
    int i, j;
    int r, l;
    int x;
    long long int ret = 0;
    for (i = 0;i < n;i++) {
        scanf("%d", &x);
        a[x]++;

    }
    for (x = 1;x <= 5000;x++) {
        if (a[x] < 2) continue;
        l = 1;
        r = x - 1;
        while (l <= r) {
            if (l == r && a[l] > 1) {
                ret += (a[x] * (a[x] - 1)) / 2 * (a[l] * (a[l] - 1)) / 2;
            }
            else if (l < r && a[l] > 0 && a[r] > 0) {
                ret += (a[x] * (a[x] - 1)) / 2 * a[l] * a[r];
            }
            l++;
            r--;
        }
    }
    ret = ret % 1000000007;
    cout << ret << endl;
    return 0;
}
