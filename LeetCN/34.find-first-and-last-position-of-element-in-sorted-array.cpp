// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=30204
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
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
    vector<int> searchRange(vector<int>& nums, int target) {
        int md;
        int ed = nums.size();
        int fr = 0;
        int l= 0;
        int r = ed-1;

        while (1) {
            
            md = fr + ed ;
            md/=2;
            if (md>=0&&md<nums.size()&&nums[md] == target) break;
            if (fr >= ed) return {-1, -1};
            if (nums[md] < target) {
                fr = md +1;
                l = fr;

            } else {
                ed = md - 1;
                r = ed;
            }
        }
        

        // now we have found the md
        auto k = md;
        int prev_r = r;
        while (1) {
            
            r = (prev_r + k) /2;

            if (nums[r] == target) {
                if (r+1 == nums.size()|| nums[r+1] > target)
                break;
                k = r + 1;
                
            } else {
                prev_r = r - 1;
            }

        }
        k = md;
        auto prev_l = l;
        while (1) {
            l = (prev_l + k) / 2;
            if (nums[l] == target ) {
                if (l == 0 || nums[l-1]< target) {
                    break;
                }
                k = l - 1;
            }
            else {
                prev_l = l + 1;
            }
        }

        return {l, r};


    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

