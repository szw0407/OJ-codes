#include<bits/stdc++.h>
using namespace std;


/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) {
            return true;
        }
        if (x < 0) {
            return false;
        }
        long long int m, n, k;
        m = log10(x);
        int i = 0;

        for (i = 0;i < m;i++) {
            // j *= 10;
            n = x % (long long int) pow(10, m - i + 1) / (long long int) pow(10, m - i);
            k = x % (long long int) pow(10, i + 1) / (long long int) pow(10, i);
            if (k != n) {
                return false;
            }

        }return true;

    }
};
// @lc code=end

