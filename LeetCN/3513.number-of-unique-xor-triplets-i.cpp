/*
 * @lc app=leetcode.cn id=3513 lang=cpp
 * @lcpr version=30204
 *
 * [3513] 不同 XOR 三元组的数目 I
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
#include <cmath>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        auto l = nums.size();
        if (l <=2) return l;
        int d = floor(log2(l))+1;
        return int(pow(2, d));

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,2]\n
// @lcpr case=end

 */

