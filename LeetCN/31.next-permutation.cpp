// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=31 lang=cpp
 * @lcpr version=30204
 *
 * [31] 下一个排列
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
    void nextPermutation(vector<int>& nums) {
        int j = nums.size() - 2;
        for (;j>=0;j--) {
            if (nums[j] < nums[j+1]) {
                
                break;
            }
        }
        // nums[j] < nums[j+1]
        // nums[j+1] >= nums[j+2] ...
        // so the nums[j+1] is the max
        int i;
        if (j>=0){  // suppose this is not a decreasing sorted array

        for (i = nums.size() - 1;i>j;i--) {
            if (nums[i] > nums[j]) break;
            // now nums[i] >= nums[i+1]
            // and we know that nums[i+1] <= nums[j] otherwise breaked
            // thus i is the max to make nums[i] > nums[j]
        }
        swap(nums[i], nums[j]);}

        reverse(nums.begin()+1+j, nums.end());
        return;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,5]\n
// @lcpr case=end

 */

