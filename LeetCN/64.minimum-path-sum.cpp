// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=64 lang=cpp
 * @lcpr version=30204
 *
 * [64] 最小路径和
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
    int minPathSum(vector<vector<int>>& grid) {
        auto m = grid.size();
        auto n = grid[0].size();

        auto res = vector<vector<int> >(m+1, vector<int>(n+1, 0));
        int i, j;
        for (i=1;i<=m;i++) {
            res[i][0] = res[i-1][1];
            for (j=1;j<=n;j++) {
                if (i == 1) {
                    res[0][j] = res[1][j-1];
                }
                res[i][j] = min(res[i-1][j], res[i][j-1]) + grid[i-1][j-1];
            }
        }
        return res[m][n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3,1],[1,5,1],[4,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6]]\n
// @lcpr case=end

 */

