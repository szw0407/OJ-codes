// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=152 lang=cpp
 * @lcpr version=30204
 *
 * [152] 乘积最大子数组
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
    int maxProduct(vector<int>& nums) {
        int i,j;
        auto p = nums.size();
        auto tmp = 1;
        auto _res = INT_MIN;
        auto d = 0;
        for (i=0;i<p;i++) {
            if (nums[i] != 0) {
                tmp*=nums[i];
                _res = max(_res, tmp);
            } else {
                for (j=d;j<i-1;j++) {
                    tmp/=nums[j];
                    _res = max(_res, tmp);
                }
                _res = max(_res, 0);
                d = i+1;
                tmp = 1;
            }
        }
                        for (j=d;j<i-1;j++) {
                    tmp/=nums[j];
                    _res = max(_res, tmp);
                }
        return _res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,-2,4]\n
// @lcpr case=end

// @lcpr case=start
// [-2,0,-1]\n
// @lcpr case=end

 */

