#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int maxn = 1;
        int nnow;
        int i, j, k;
        bool f;
        string res = s.substr(0, 1);
        for (i = 0;i < s.size();i++) {
            if (i+maxn >= s.size())break;
            for (j = i + 1;j < s.size();j++) {
                f = true;
                for (k = 1;j-k>=i;k++) {
                    if (s[j - k] != s[j + k]) {
                        f = false;
                        break;
                    }
                }

                if (f) {
                    nnow = (j - i) * 2 + 1;
                    if (maxn < nnow) {
                        res = s.substr(i, nnow);
                        maxn = nnow; 
                    }
                    continue;
                }
                f = true;
                for (k = 0;j-k>i;k++) {
                    if (s[j - k - 1] != s[j + k]) {
                        f = false;
                        break;
                    }
                }
                if (f) {
                    nnow = (j - i) * 2;
                    if (nnow > maxn) {
                        res = s.substr(i, nnow);
                        maxn = nnow;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

