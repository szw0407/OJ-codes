#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int maxcnt = 0;
        unordered_map<char,int> rec;
        int i, j;
        int tmp = 0;
        int lt = 0;
        for (i=0;i<s.length();i++){
            if (rec.count(s[i]) && rec[s[i]] >= lt) {
                maxcnt = max(i - lt, maxcnt);
                lt = rec[s[i]] + 1;
            }
            rec[s[i]] = i;
        }
        maxcnt = max(i - lt, maxcnt);
        return maxcnt;
    }
};
// @lc code=end

