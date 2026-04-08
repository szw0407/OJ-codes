// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=153 lang=cpp
 * @lcpr version=30204
 *
 * [153] 寻找旋转排序数组中的最小值
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
#include <cmath>

// @lcpr-template-end
// @lc code=start
// class cmp {
//     public:
//     bool operator()(const int& a, const int& b) const {
//         return a>b;
//     }
// };
// #define i (ceil((l+r)/2.0))
class Solution {
public:
    int findMin(vector<int>& nums) {
        // priority_queue<int, vector<int>, cmp> data;
        // for (auto n:nums) data.push(n);
        // return data.top();
        const auto len = nums.size();
        auto q = nums.back();
        int l = 0;
        int r = len - 1;
        int i;
        while (l < r) {
            bool t = true;
            i = (((l+r)/2));
            if (i > 0) {
                if (nums[i-1] < nums[i]) t = false;
            } 
            if (i < len-1) {
                if (nums[i] > nums[i+1]) t = false;
            }
            if (t) return nums[i];
            
            if (nums[i] > q) {
                l = i+1;
            } else {
                
                r = i - 1;
            }
        }
        return nums[(((l+r)/2))];

    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [11,13,15,17]\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n
// @lcpr case=end
 */

