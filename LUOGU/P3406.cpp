#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int i, j;
    int k;
    
    
    auto p = new vector<int>(n + 1, 0);   // path
    auto route = new vector<int>;
    int prev;
    for (i = 0;i < m;i++) {
        cin >> k;
        route->push_back(k);
        if (i == 0) continue;
        prev = route->at(i - 1);
        if (prev > k) {
            swap(prev, k);
        }
        p->at(prev)++;
        p->at(k)--;
    }
    auto num = new vector<uint64_t >;
    prev = 0;
    for (i = 0;i < n;i++) {
        prev += p->at(i);
        num->push_back(prev);
    }
    uint64_t res = 0;
    for (i = 1;i < n;i++) {
        int a1, b1, c1;
        cin >> a1 >> b1 >> c1;
        res += min((a1 * num->at(i)), (b1 * num->at(i) + c1));
    }
    cout << res << endl;
    return 0;
}