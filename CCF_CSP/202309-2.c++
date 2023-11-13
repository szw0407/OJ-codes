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
    int l, r;
    double op[100002][2] = { {1,0} };
    double num;
    int optnum;
    double k = 1.0;
    double t = 0.0;
    for (i = 1;i <= n;i++) {
        cin >> optnum >> num;
        if (optnum == 1) {
            k *= num;
        }
        else {
            t += num;
        }
        op[i][0] = k;
        op[i][1] = t;
    }
    for (i = 0;i < m;i++) {
        cin >> l >> r >> x >> y;
        l--;
        
            t = op[r][1] - op[l][1];
            k = op[r][0] / op[l][0];
        
        cout << fixed << (x * cos(t) - y * sin(t)) * k << ' ' << (x * sin(t) + y * cos(t)) * k << '\n';
    }
    return 0;
}