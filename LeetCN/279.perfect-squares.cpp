/*
 * @lc app=leetcode.cn id=279 lang=cpp
 * @lcpr version=30204
 *
 * [279] 完全平方数
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
#include <cstdlib>
#include <cstdio>

#include <cmath>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> cache(n+1);
        int i;
        int j;
        int t;
        for (i=1;i<=n; i++) {
            t = INT_MAX;
            for (j=1;j * j <= i;j++) {
                
                t = min(t, cache[i-j*j]);
            }
            cache[i] = t+1;

        }

        return cache[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 13\n
// @lcpr case=end

 */

