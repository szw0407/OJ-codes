/*
 * @lc app=leetcode.cn id=32 lang=cpp
 * @lcpr version=30204
 *
 * [32] 最长有效括号
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
    int longestValidParentheses(string s) {
        int max_res = 0;
        auto max_len = s.size();
        stack<int> st;
        st.push(-1);
        int i;
        bool p = false;
        int tmp = 0;
        for (i=0;i<max_len;i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.top() >=0 && s[st.top()] == '(') {
                    // match
                    st.top();

                    st.pop();
                    auto tmp_b = st.top();
                    
                    tmp = i - tmp_b;
                    max_res = max(max_res, tmp);
                } else {
                    // max_res = max(max_res, tmp);
                    // tmp = 0;
                    st.push(i);
                }
            }
        }
        // max_res = max(max_res, tmp);
        return max_res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "(()"\n
// @lcpr case=end

// @lcpr case=start
// ")()())"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

 */

