#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

 // @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int res;
        int f;
        while (s[i] == ' ') {
            i++;
        }
        if (s[i] == '-') {
            i++;
            while (s[i] == '0') {
                i++;
            }
            f = i;
            while (s[i] >= '0' && s[i] <= '9' && i < s.size()) {
                i++;
            }
            s = s.substr(f, i - f);
            if ((s.size() < 10 || s <= "2147483648") && s.size() < 11) {
                res = 0;
                for (i = 0;i < s.size();i++) {
                    res *= 10;
                    res -= s[i] - '0';
                }
                return res;
            }
            else return -2147483648;

        }
        else {
            if (s[i] == '+') {
                i++;
            }
            while (s[i] == '0') {
                i++;
            }
            f = i;
            while (s[i] >= '0' && s[i] <= '9' && i < s.size()) {
                i++;
            }
            s = s.substr(f, i - f);
            if ((s.size() < 10 || s <= "2147483647") && s.size() < 11) {
                res = 0;
                for (i = 0;i < s.size();i++) {
                    res *= 10;
                    res += s[i] - '0';
                }
                return res;
                
            }
            else return 2147483647;
        }

    }
};
// @lc code=end

