/*
 * @lc app=leetcode.cn id=38 lang=cpp
 * @lcpr version=30204
 *
 * [38] 外观数列
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
    unordered_map<int, string> cache = {
        {1, "1"}
    };
    string countAndSay(int n) {
        if (cache.contains(n)) return cache[n];
        int tmp = 0;
        char current_ch = NULL;
        string res = "";
        auto prev = countAndSay(n-1);

        for (auto ch: prev) {
            if (ch == current_ch) {
                tmp++;

            } else {
                if (current_ch == NULL) {
                    current_ch = ch;
                    tmp = 1;
                    continue;
                }
                res += to_string(tmp);
                tmp = 1;
                res+=current_ch;
                current_ch = ch;
            }
        }
        res += to_string(tmp);
        res+=current_ch;
        cache[n] = res;
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

