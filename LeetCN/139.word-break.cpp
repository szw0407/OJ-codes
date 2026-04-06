// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=139 lang=cpp
 * @lcpr version=30204
 *
 * [139] 单词拆分
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
    // unordered_set<int> failed;
    bool wordBreak(string &s, vector<string> &wordDict, int st, unordered_set<int> &failed) {
        int i, j;
        if (st == s.length()) return true;
        if (failed.contains(st)) return false;
        bool ans = false;
        i = st;
        for (auto w:wordDict) {
            auto k = true;
            if (i+w.length()>s.length()) continue;
            for (j=0;j<w.length();j++) {
                if (s[i+j] != w[j]) {k = false;break;}
            }
            if (k) {
                ans = ans || wordBreak(s, wordDict, i+j, failed);
                if (ans) return true;
                else failed.insert(st);
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        auto t = unordered_set<int>();
        return wordBreak(s, wordDict, 0, t);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leetcode"\n["leet", "code"]\n
// @lcpr case=end

// @lcpr case=start
// "applepenapple"\n["apple", "pen"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats", "dog", "sand", "and", "cat"]\n
// @lcpr case=end
// @lcpr case=start
// "cars"\n["car","ca","rs"]\n
// @lcpr case=end
 */

