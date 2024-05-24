#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        char s[15] = { 0 };
        char a1[]="-2147483648";
        char a2[]="2147483647";
        sprintf(s, "%d", x);
        char out[15] = { 0 };
        int i;
        int j = 0;
        if (s[0] == '-') {
            out[0] = '-';
            for (i = strlen(s) - 1;i > 0;i--) {
                j++;
                out[j] = s[i];
            }
            if (strlen(out)==strlen(a1) && strcmp(out, a1)>0) {
                return 0;
            }
        }
        else {
            for (i = strlen(s) - 1;i >= 0;i--) {
                out[j] = s[i];
                j++;
            }
            if (strlen(out)==strlen(a2) && strcmp(out, a2)>0) {
                return 0;
            }
        }
        int res;
        sscanf(out, "%d", &res);
        return res;
    }
};
// @lc code=end

