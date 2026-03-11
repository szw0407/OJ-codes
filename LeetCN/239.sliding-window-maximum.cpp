// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 * @lcpr version=30204
 *
 * [239] 滑动窗口最大值
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int i, j;
        for (i=0;i<k-1;i++) {
            while (q.size() != 0 && nums[i] > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        vector<int> ret = {};
        
        for (i=k-1;i<nums.size();i++) {
            while (q.size() != 0 && nums[i] > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (i - k >= q.front()) {
                q.pop_front();
            }
            ret.push_back(nums[q.front()]);
        }
        return ret;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,-1,-3,5,3,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

