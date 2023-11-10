#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int i;
    int t, c;
    int num[2000005] = {0};
    int q;
    for (i = 0;i < n;i++) {
        cin >> t >> c;
        if (t - c < 0) {
            num[1]++;
        }
        else {
            num[t - c + 1]++;
        }
        num[t+1]--;
    }
    for (i = 1;i < 2000005;i++) {
        num[i] += num[i - 1];
    }
    for (i = 0;i < m;i++) {
        cin >> q;
        q += k;
        cout << num[q] << '\n';
    }

    return 0;
} 