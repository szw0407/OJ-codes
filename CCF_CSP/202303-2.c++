#include<bits/stdc++.h>
struct field {
    long long int t;
    long long int c;
};
using namespace std;
bool cmp(field a, field b) {
    if (a.t != b.t) return a.t > b.t;
    else return a.c < b.c;
}
int main() {
    long long int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    field f[100005];
    long long int i;
    
    for (i = 0;i < n;i++) {
        scanf("%lld%lld", &f[i].t, &f[i].c);
    }
    f[i].t = k;  // the minimal time should be no less than k
    i = 0;
    long long int j = 0;

    long long int ind = 1;
    long long int total_cost, total_step;
    sort(f, f + n, cmp);
    long long int time = f[0].t;
    long long int cost = f[0].c;
    long long int dt;
    while (m > 0 && time > k) {
        while (time == f[ind].t) {
            // f[i] whose i<= ind, their time should have been eq time
            cost += f[ind].c;
            ind++;
            if (ind == n) {
                break;
            }
        }
        dt = time - f[ind].t;
        if (dt * cost <= m) {
            //use all the resources
            time = f[ind].t;
            m -= dt * cost;
        }
        else {
            // calculate how much time to reduce
            time -= m / cost;
            break;
        }
    }
    printf("%d", time);
    return 0;
}