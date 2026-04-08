/*
 * @lc app=leetcode.cn id=189 lang=cpp
 * @lcpr version=30204
 *
 * [189] 轮转数组
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
    void rotate(vector<int>& nums, int k) {
        // for (int i = 0;i<k;i++) {
            // int t = nums.back();
            k = k % nums.size();
            auto t = vector<int>();
            for (int i = nums.size()-k;i<nums.size();i++) {
                t.push_back(nums[i]);
            }
            for (int j=nums.size()-1;j>=k;j--) {
                nums[j] = nums[j-k];
            }
            for (int i=0;i<k;i++) {
                nums[i] = t[i];
            }
        // }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [-1,-100,3,99]\n2\n
// @lcpr case=end

 */

