#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<iostream>
#include<cstdlib>

using namespace std;

bool cmp(const string& a, const string& b) {
    if (a + b > b + a) {
        return true;
    }
    else {
        return false;
    }
}

int main(int argc, char* argv[]) {
    int n;
    string a[25];
    cin >> n;
    int i;
    for (i = 0;i < n;i++) {
        cin >> a[i];
    }
    sort(&a[0], &a[n], cmp);
    for (i = 0;i < n;i++) {
        cout << a[i];
    }
    return 0;
}