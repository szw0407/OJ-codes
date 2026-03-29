// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=416 lang=cpp
 * @lcpr version=30204
 *
 * [416] 分割等和子集
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
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 2) return false;
        int current_sum = 0;
        int tot = 0;
        for (int i=0;i<nums.size();i++) {
            tot+=nums[i];
        }
        if (tot % 2) return false;
        tot/=2;

        auto prev = new vector<bool>(tot+1, false);
        prev->at(0) = true;   

        int i,j;
        for (i=0;i<nums.size();i++) {
            auto n = nums[i];
            for (j=tot;j>=nums[i];j--) {
                prev->at(j) = prev->at(j-nums[i]) || prev->at(j);
                if (prev->at(tot)) return true;
            }
        }
        return false;

        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,5,11,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5]\n
// @lcpr case=end

 */

