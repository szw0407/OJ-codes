/*
 * @lc app=leetcode.cn id=75 lang=cpp
 * @lcpr version=30204
 *
 * [75] 颜色分类
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
    void sortColors(vector<int>& nums) {
        uint32_t a = 0;
        uint32_t b = nums.size()-1;
        uint32_t cnt = 0;
        for (cnt = 0;cnt<nums.size();cnt++){
            while (nums[cnt] != 1) {
                if (nums[cnt] == 0 && cnt > a) {
                    swap(nums[cnt], nums[a]);
                    a++;
                }
                if (nums[cnt] == 2 && cnt < b) {
                    swap(nums[cnt], nums[b]);
                    b--;
                }
                if (nums[cnt] == 0 && cnt <= a) break;
                if (nums[cnt] == 2 && cnt >= b) break;
            }
        }
        
        

    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,1]\n
// @lcpr case=end

 */

