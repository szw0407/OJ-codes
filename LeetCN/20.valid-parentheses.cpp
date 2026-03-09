/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30204
 *
 * [20] 有效的括号
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
    bool isValid(string s) {
        // int anum = 0;
        // int bnum = 0;
        // int cnum = 0;
        vector<char> st;
        auto n = s.size();

        int i;
        for (i=0;i<n;i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {

                st.push_back(s[i]);
            } else {
                if (st.size() == 0) return false;
                char bk = st.back();
                if (bk!= s[i]- 1 && bk != s[i] -2) return false; 
                st.pop_back();
            }
    }
    if (st.size()) return false;
    return true;
}
};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

// @lcpr case=start
// "([)]"\n
// @lcpr case=end

 */

