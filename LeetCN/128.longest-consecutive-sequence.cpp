/*
 * @lc app=leetcode.cn id=128 lang=cpp
 * @lcpr version=30204
 *
 * [128] 最长连续序列
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
#include <set>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for (int num : nums) s.insert(num);
        int max_l = 0;

        auto n = s.size();
        int tmp = INT_MIN;
        for (int num : s) {
            if (num < tmp ) continue;
            tmp = 0;

            while (1) {
                tmp++;
                if (!s.contains(num+tmp)) break;
            }

            max_l = max(tmp,max_l);
            tmp = num+tmp;



        }
        return max_l;


    }
};
// @lc code=end



/*
// @lcpr case=start
// [100,4,200,1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,7,2,5,8,4,6,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,2]\n
// @lcpr case=end

 */

