/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=30204
 *
 * [53] 最大子数组和
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
    int maxSubArray(vector<int>& nums) {
        int i;
        // vector<int> max_sum_bf;
        int max_sum = nums[0];
        int tmp = nums[0];
        for (i=1;i<nums.size();i++) {
            if (tmp >= 0) {
                tmp += nums[i];
            } else {
                tmp = nums[i];
            }
            max_sum = max(tmp, max_sum);
        }
        return max_sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */

