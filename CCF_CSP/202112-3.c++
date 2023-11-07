#include<bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int w, s;
    cin >> w >> s;
    string str;
    int i = 0;
    int j = 0;
    vector<int> g = { 1 };
    vector<int> vect_2;
    cin >> str;
    int k = 1;
    vector<char> num;
    int p, q;
    vector<int>::iterator it2;
        for (string::iterator it = str.begin();it < str.end();it++) {
        if ('0' <= *it && *it <= '9') {
            if (k == 1 || k==2) {
                num.push_back(28);
            }
            num.push_back(*it - '0');
            k = 3;
        }
        else if ('A' <= *it && *it <= 'Z') {
            if (k == 3) {
                num.push_back(28);
            }
            else if (k==2)
            {
                num.push_back(28);
                num.push_back(28);
            }
            num.push_back(*it - 'A');
            k = 1;
        }
        else {
            if (k == 1 || k == 3) {
                num.push_back(27);
            }
            num.push_back(*it - 'a');
            k = 2;
        }
    }
    if (num.size() % 2) {
        num.push_back(29);
    }
    vector<int> res = { 0 };
    for (i = 0;i < num.size();i += 2) {
        res.push_back(num[i] * 30 + num[i + 1]);
    }
    int LEN_OF_CHK;
    if (s >= 0)
        LEN_OF_CHK = pow(2, s + 1);
    else LEN_OF_CHK = 0;
    int NUM_OF_900 = w - (res.size() + LEN_OF_CHK) % w;
    if (NUM_OF_900 == w) {
        NUM_OF_900 = 0;
    }
    for (i = 0;i < NUM_OF_900;i++) {
        res.push_back(900);
    }
    res.at(0) = res.size();
    int tmp;
    for (it2 = res.begin(); it2 < res.end();it2++) {
        tmp = *it2;
        cout << tmp << '\n';
    }
    if (s > -1) {
        s = LEN_OF_CHK;
        
        for (i = 0;i < s;i++) {
            res.push_back(0);
        }
        for (i = 1;i < s + 1;i++) {
            g.push_back(0);
            p = 1;
            for (j = 0;j < i;j++) {
                p *= 3;
                p = p % 929;
            }
            p = 929 - p;
            vect_2 = g;
            for (j = 1;j <= i;j++) {
                g.at(j) = (g[j] + p * vect_2[j - 1]) % 929;
            }
        }
        tmp = res[0];
        for (i = 0;i < tmp;++i) {
            q = res[i];
            for (j = 0;j < g.size();j++) {
                res.at(i + j) = (res[i + j] - q * g[j]) % 929;
            }
        }

        for (it2 = res.end() - s;it2 < res.end();it2++) {
            tmp = -(*it2) % 929;
            if (tmp < 0) {
                tmp += 929;
            }
            cout << tmp << '\n';
        }
    }
    return 0;
}