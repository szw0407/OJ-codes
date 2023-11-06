#include<bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int i;
    int64_t a[100002];  // range (0,1e9)
    int64_t tot = 0;
    int64_t r;
    int n;
    int64_t N;
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
        tmp = 0;  // reset to 0 for range [a[i], a[i+1])
        // Usually the max num is not reached
        // in this range, f(x) equals i
        l_num = a[i];
        do {
            x = l_num / r; 
            r_num = (x + 1) * r; // then in range[l_num, r_num), g(x) is THE same value
            if (r_num>a[i+1]) r_num=a[i+1]; // otherwise f(x) is larger than i
            tmp += abs(i - x) * (r_num - l_num);
            // cout << l_num << ' ' << r_num-1 << ' '<< abs(i-x)  << endl;
            l_num = r_num;
        } while (l_num < a[i + 1]);
        tot += tmp;
    }
    cout << tot << endl;
    return 0;
}