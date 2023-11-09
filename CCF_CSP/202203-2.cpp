#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    int i;
    int tmp1, tmp2;
    int t[100002];  // start time
    int e[100002];  // end time
    int c[100002];
    for (i = 0;i < n;i++) {
        cin >> t[i] >> c[i];
        e[i] = t[i] - c[i];  // in this time period e[i] ~ t[i]
    }
    int q[100002];
    int j;
    int cnt;
    for (i = 0;i < m;i++) {
        cin >> q[i];
        q[i] += k;
        cnt = 0;
        // now we begin searching 
        // search in front
        for (j = 0;j < n;j++) {
            if (t[j] < q[i]) continue;
            if (e[j] < q[i]) {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}