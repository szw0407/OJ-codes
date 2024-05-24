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
        int i;
        int j;
        int tmp;
        for (i = 0;i < numRows;i++) {
            j = i;
            if (i>=s.size()) break;
            res.push_back(s[j]);
            while (j < s.size())
            {
                
                tmp = (numRows - 1 - i) * 2;
                if (tmp > 0) {
                    j += tmp;
                    if (j>=s.size()) break;
                    res.push_back(s[j]);
                }
                tmp = (i) * 2;
                if (tmp > 0) {
                    j += tmp;
                    if (j>=s.size()) break;
                    res.push_back(s[j]);
                }
            }
            
        }
        return res;
    }
};
// @lc code=end

