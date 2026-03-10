/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=30204
 *
 * [70] 爬楼梯
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
    int climbStairs(int n) {
        __int128_t a = 1;
        __int128_t b = 1;
        int i;
        __int128_t tmp;
        
        for (i=0;i<n;i++) {
            tmp = a+b;
            b = a;
            a = tmp;
        }
        return b;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

