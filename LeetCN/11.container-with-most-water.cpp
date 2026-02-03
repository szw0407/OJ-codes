// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 * @lcpr version=30204
 *
 * [11] 盛最多水的容器
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
    int maxArea(vector<int>& height) {
        auto num = height.size();
        // int res = 0;

        int a = 0;
        int b = num -1;
        int res = (b-a) * min(height[b], height[a]);
        
        while (a<b){
            if (height[a] < height[b]){
                auto ha = height[a];
                while (a < b && height[a] <= ha)
                {
                    a++;
                }res = max(res, (b-a) * min(height[b],height[a]));
                
            } else {
                auto hb = height[b];
                while(a<b && height[b] <= hb){
                    b--;
                }res = max(res, (b-a) * min(height[b],height[a]));
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,8,6,2,5,4,8,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */

