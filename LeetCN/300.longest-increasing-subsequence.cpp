// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=300 lang=cpp
 * @lcpr version=30204
 *
 * [300] 最长递增子序列
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
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        auto rec = new vector<int>(1, nums[0]);
        int i;
        for (i=1;i<nums.size();i++) {
            // if (nums[i] > rec->back()) {
            //     rec->push_back(nums[i]);
            // } else {
                int l = 0;
                int r = rec->size()-1;
                int tmp;
                while (l <= r) {
                    tmp = (l+r)/2;
                    if (rec->at(tmp) > nums[i]) {
                        if (tmp == 0 || rec->at(tmp-1) < nums[i]) {
                            rec->at(tmp) = nums[i];
                            break;
                        }
                        r = tmp -1;
                    } else if (rec->at(tmp) == nums[i]) break;
                    else
                    {
                        if (tmp == rec->size()-1) {
                            rec->push_back(nums[i]);
                            break;
                        }
                        l = tmp + 1;
                    }
                }
            // }
        }
        
        return rec->size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,9,2,5,3,7,101,18]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7,7]\n
// @lcpr case=end

 */

