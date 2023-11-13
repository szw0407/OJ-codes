#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m, n;
    cin >> n >> m;
    int i;
    int j;
    double x, y;
    int q, r;
    double op[100000][2];
    double k = 1.0;
    double t = 0.0;
    for (i = 0;i < n;i++) {
        cin >> op[i][0] >> op[i][1];
    }
    for (i = 0;i < m;i++) {
        cin >> q >> r >> x >> y;
        k = 1.0;
        t = 0.0;
        for (j = q - 1;j < r;j++) {
            if (op[j][0] == 1) {
                k *= op[j][1];
            }
            else {
                t += op[j][1];
            }
        }
        cout << fixed << (x * cos(t) - y * sin(t)) * k << ' ' << (x * sin(t) + y * cos(t)) * k << '\n';

    }
    return 0;
}