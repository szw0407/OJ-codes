// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=560 lang=cpp
 * @lcpr version=30204
 *
 * [560] 和为 K 的子数组
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
    int subarraySum(vector<int>& nums, int k) {
        auto pref_sum = unordered_map<int, int>();
        pref_sum[0] = 1;
        auto t = 0;
        auto res = 0;
        for (int i = 0;i<nums.size();i++) {
            auto n = nums[i];
            t+=n;res+=pref_sum[t-k];
            pref_sum[t]++;
            
            
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end
// @lcpr case=start
// [1]\n0\n
// @lcpr case=end
 */

