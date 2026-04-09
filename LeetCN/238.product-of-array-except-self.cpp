/*
 * @lc app=leetcode.cn id=238 lang=cpp
 * @lcpr version=30204
 *
 * [238] 除了自身以外数组的乘积
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
    vector<int> productExceptSelf(vector<int>& nums) {
        int i;
        auto ans = vector<int>(nums.size(), 1);
        auto l_pd = 1;
        auto r_pd = 1;
        for (i=1;i<nums.size();i++) {
            ans[i] = l_pd * nums[i-1];
            l_pd = ans[i];
        }
        for (i = nums.size()-1;i>=0;i--) {
            ans[i] = r_pd * ans[i];
            r_pd *= nums[i];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [-1,1,0,-3,3]\n
// @lcpr case=end

 */

