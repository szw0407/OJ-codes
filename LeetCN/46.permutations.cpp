// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30204
 *
 * [46] 全排列
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
    unordered_set<int> visited;
    int k;
    void sol(unordered_set<int> &visited, vector<int> &nums, vector<vector<int> > &final_res, vector<int> &current) {
        if (visited.size() == k) {
            // all things have been put
            final_res.push_back(vector<int>(current));
            return;
        }
        int i;
        for (i=0;i<k;i++) {
            if (visited.contains(i)) continue;
            // this time we put i into it
            visited.insert(i);
            current.push_back(nums[i]);
            sol(visited, nums, final_res, current);
            current.pop_back();
            visited.erase(i);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // auto res = new vector<vector<int>>();
        vector<vector<int> > res;

        k = nums.size();
        vector<int> current;
        sol(visited, nums, res, current);
        return res;



    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

