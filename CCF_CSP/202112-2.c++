#include<bits/stdc++.h>
using namespace std;

int64_t r;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    long long int i, j;
    long long int a[100002];
    long long int tot = 0;
    int n;
    long long N;
    cin >> n >> N;
    r = N / (n + 1);
    for (i = 1;i <= n;i++) {
        cin >> a[i];
    }
    a[i] = N;
    __int64 tmp;
    __int64 r_num;
    __int64 l_num;
    int64_t x;
    for (i = 0;i < n + 1;i++) {
        tmp = 0;
        l_num = a[i];
        while (l_num < a[i + 1]) {
            x = l_num / r;
            r_num = (x + 1) * r;
            if (r_num>a[i+1]) r_num=a[i+1];
            tmp += abs(i - x) * (r_num - l_num);
            // cout << l_num << ' ' << r_num-1 << ' '<< abs(i-x)  << endl;
            l_num = r_num;
        }
        tot += tmp;
    }
    cout << tot << endl;
    return 0;
}