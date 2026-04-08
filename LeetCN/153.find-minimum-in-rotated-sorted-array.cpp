/*
 * @lc app=leetcode.cn id=153 lang=cpp
 * @lcpr version=30204
 *
 * [153] 寻找旋转排序数组中的最小值
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
class cmp {
    public:
    bool operator()(const int& a, const int& b) const {
        return a>b;
    }
};
class Solution {
public:
    int findMin(vector<int>& nums) {
        priority_queue<int, vector<int>, cmp> data;
        for (auto n:nums) data.push(n);
        return data.top();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [11,13,15,17]\n
// @lcpr case=end

 */

