// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30204
 *
 * [78] 子集
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
    void sol (
        vector<int> &nums,
        int a, vector<int> &current_subset, vector<vector<int> > &res, int l
    ) {
        if (current_subset.size() == a) {
            res.emplace_back((current_subset));
            return;
        }
        
        for (int i = l;i<nums.size();i++) {
            // if (visited.contains(n)) continue;
            auto n = nums[i];
            current_subset.push_back(n);
            sol(nums, a, current_subset,  res, i+1);
            current_subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int a = 0;
        vector<int> current_subset;
        vector<vector<int> > res;
        for (a=0;a<=nums.size();a++)
        sol(nums, a, current_subset, res, 0);
        return res;
        

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

