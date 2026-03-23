/*
 * @lc app=leetcode.cn id=45 lang=cpp
 * @lcpr version=30204
 *
 * [45] 跳跃游戏 II
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
    int jump(vector<int>& nums) {
        // auto rec = new vector<int>(nums.size(), INT_MAX);
        int steps =0;
        int fst = 0;
        int pt = 0;
        int i;
        for (i=0;i<nums.size();i++) {
            fst = max(nums[i]+i, fst);
            fst = min(fst, (int)nums.size()-1);
            if (i == pt) {
                steps++;
                pt = fst;
            }
        }
        return steps-1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,0,1,4]\n
// @lcpr case=end

 */

