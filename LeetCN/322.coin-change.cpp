// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30204
 *
 * [322] 零钱兑换
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
    unordered_map<int, int> cache = {{0,0}};
    int coinChange(vector<int>& coins, int amount) {
        // auto min_res = 0;
       int t = INT_MAX;
        if (cache.contains(amount)) return cache[amount];
        for (auto c : coins) {
            if (c <= amount){
                auto tmp = coinChange(coins, amount-c);
                if (tmp == -1) {
                    continue;
                }
                t = min(tmp+1, t);
            }
        }
        if (t == INT_MAX) t = -1;
        cache[amount] = t;
        return t;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

