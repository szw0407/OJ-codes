/*
 * @lc app=leetcode.cn id=347 lang=cpp
 * @lcpr version=30204
 *
 * [347] 前 K 个高频元素
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
        bool operator() (const pair<int, int> &a, const pair<int,int> &b) const {
            return a.second < b.second;
        }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, pair<int, int> > cnt;
        for (auto n : nums) {
            if (!cnt.contains(n)) {
                cnt[n] = pair<int, int>(n, 1);
            } else cnt[n].second++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
        for (auto p : cnt) {
            pq.push(p.second);
        }
        vector<int> res;
        for (auto i = 0;i<k;i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,2,1,2,3,1,3,2]\n2\n
// @lcpr case=end

 */

