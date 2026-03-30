// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=84 lang=cpp
 * @lcpr version=30204
 *
 * [84] 柱状图中最大的矩形
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
#include <map>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        auto n = heights.size();
        int i;
        map<int, int> t;
        t[heights[0]] = 0;
        int bg = -1;
        int max_sum = heights[0];
        for (i=1;i<n;i++) {
            int h = 0;
            // int j;
            int lp = -1;
            for (auto d:t) {
                lp = d.second;
                h = d.first;
                if (h<=heights[i]) {
                    auto s = h * (i - lp + 1);
                    max_sum = max(s, max_sum);
                } else {
                    break;
                }
                
            }
            
            if (h < heights[i]) {
                t[heights[i]] = i;
                max_sum = max(max_sum, heights[i]);
            }
            else {

                t.erase(t.upper_bound(heights[i]), t.end());
                if (t.size() == 0) {
                    if (heights[i] == 0) {
                        bg = i;
                        continue;
                    }
                    t[heights[i]] = bg+1;
                    max_sum = max(max_sum, heights[i] * (i-bg));
                }
                else if (lp >=0 && !t.contains(heights[i])) {
                    t[heights[i]] = lp;
                    max_sum = max(max_sum, heights[i]*(i+1-lp));
                }
            }
               
            
            
        }
        return max_sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,5,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

 */

