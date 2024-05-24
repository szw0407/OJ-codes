#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string res;
        string tmp[numRows];
        int j = 1;
        int d = -1;
        int i;
        for (i = 0;i < s.size();i++) {
            j += d;
            if (j == numRows - 1 || j == 0) {
                d = -d;
            }
            tmp[j].push_back(s[i]);
        }
        for (i = 0;i < numRows;i++) {
            res.append(tmp[i]);
        }
        return res;
    }
};
// @lc code=end

