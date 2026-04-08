// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=189 lang=cpp
 * @lcpr version=30204
 *
 * [189] 轮转数组
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0) return;
        auto loop = gcd(k,nums.size());

        for (unsigned int i = 0;i<loop;i++) {
            auto p =nums.size()+ i - k;
            auto bk = nums[p];
            signed int j = p;
            while (j!=i)
            {
                if (j>=k)
                nums[j] = nums[j-k];
                else 
                nums[j] = nums[j-k+nums.size()];
                j -= k;
                if (j < 0) {
                    j += nums.size();
                }
            }
            nums[i] = bk;
        }

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [-1,-100,3,99]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

