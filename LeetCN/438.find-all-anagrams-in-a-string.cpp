/*
 * @lc app=leetcode.cn id=438 lang=cpp
 * @lcpr version=30204
 *
 * [438] 找到字符串中所有字母异位词
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        auto cnt = vector<int>(26,0);
        for (auto ch:p) {
            cnt[ch - 'a']++;
        }
        vector<int> res;
        for (int i=0;i+p.length() <=s.length();i++) {
            auto wdcnt = vector<int>(26, 0);
            for (int j = 0;j<p.length();j++) {
                wdcnt[s[i+j]-'a']++;
            }
            bool st = true;
            for (int j = 0;j<26 && st;j++) {
                if (wdcnt[j]!=cnt[j]) st=false;
            }
            if (st) res.push_back(i);
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abab"\n"ab"\n
// @lcpr case=end

 */

