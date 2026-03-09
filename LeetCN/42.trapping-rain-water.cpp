/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=30204
 *
 * [42] 接雨水
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
    int trap(vector<int>& height) {
        int lmax = 0;
        int rmax = 0;
        vector<int> lmaxes(height.size(), 0);
        vector<int> rmaxes(height.size(), 0);
        for (int i=0;i<height.size();i++) {
            lmaxes[i] = lmax;
            if (lmax < height[i]) lmax = height[i];
            
        }
        for (int i=height.size()-1;i>=0;i--) {
            rmaxes[i] = rmax;
            if (rmax < height[i]) rmax = height[i];
        }
        int res = 0;
        for (int i=0;i<height.size();i++) {
            auto t = min(lmaxes[i], rmaxes[i]);
            if (t > height[i] ) {
                res += t - height[i];
            }
        }
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */

