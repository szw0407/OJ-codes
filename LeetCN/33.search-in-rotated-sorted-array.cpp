// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=33 lang=cpp
 * @lcpr version=30204
 *
 * [33] 搜索旋转排序数组
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
    int search(vector<int>& nums, int target) {
        auto k = nums.back();
        int n = nums.size();
        int t = 0;
        int res = -1;
        int p;
        while (true){
            p = n+t;
            p/=2;
            if (nums[p] == target) return p;
            if (n  <= t) return -1;
        if (nums[p] > k && target <= k || target <= k && nums[p] <= target || target > nums[p] && nums[p] > k) {
            t = p+1;
        } else {
            n = p-1;
        }}
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,5,6,7,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5]\n5
// @lcpr case=end

// @lcpr case=start
// [3,5,1]\n1
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n6
// @lcpr case=end

 */

