// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=131 lang=cpp
 * @lcpr version=30204
 *
 * [131] 分割回文串
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
// a a b a (a)
// aa b a
// a aba
// a a b a
// 
// aa b a a
// a aba a
// a a b a a
// aa b aa
// aabaa
// a a b aa

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res = {{}};
        int i;
        for (i=0;i<s.length();i++) {
            vector<vector<string> > new_match = {};
            for (auto &k : res) {
                if (k.size()){
                int j = i - k.back().length() - 1;
                if (j >= 0 && s[j] == s[i] && k.size()>=2 &&prev(prev(k.end()))->length() == 1) {
                    // match
                    new_match.push_back(vector<string>(k));
                    new_match.back().pop_back();
                    new_match.back().back() = 
                    s.substr(j, i-j+1);
                } }
                if (k.size() && k.back().length() == 1 && k.back()[0] == s[i]) {
                    new_match.push_back(vector<string>(k));
                    new_match.back().back() = s.substr(i-1, 2);
                }
            
                k.push_back(string(1, s[i]));
            }
            for (auto k:new_match) {
                res.push_back(k);
            }

        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

// @lcpr case=start
// "aabaa"\n
// @lcpr case=end

 */

