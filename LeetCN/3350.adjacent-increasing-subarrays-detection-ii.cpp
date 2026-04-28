/*
 * @lc app=leetcode.cn id=3350 lang=cpp
 * @lcpr version=30204
 *
 * [3350] 检测相邻递增子数组 II
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
    int maxIncreasingSubarrays(vector<int>& nums) {
        auto a = vector<int>();
        int i;
        int curr = 1;

        for (i=1;i<nums.size();i++) {
            if (nums[i] > nums[i-1]) {
                curr++;
            } else {
                a.push_back(curr);
                curr=1;
            }
        }
        a.push_back(curr);
        if (a.size() == 1) {
            return a[0]/2;
        }
        pair<int, int> k  = {a[0]/2, a[0]/2};
        
        
        for (i=1;i<a.size();i++) {
            if (min(k.first, k.second) < min(a[i-1], a[i])) {
                k = {a[i-1], a[i]};
            }
            if (min(k.first, k.second) < (a[i]/2)) {
                k = {a[i]/2, a[i]/2};
            }
            
        }
        return min(k.first, k.second);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,5,7,8,9,2,3,4,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,4,4,4,5,6,7]\n
// @lcpr case=end

 */

