/*
 * @lc app=leetcode.cn id=118 lang=cpp
 * @lcpr version=30204
 *
 * [118] 杨辉三角
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

    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        int i;
        for (i=0;i<numRows; i++) {
            auto t = vector<int>();
            for (int j=0;j<i;j++) {
                if (j == 0) t.push_back(1);
                else {
                    t.push_back(res.back()[j-1]+res.back()[j]);
                }
            }
            t.push_back(1);
            res.push_back(move(t));
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

