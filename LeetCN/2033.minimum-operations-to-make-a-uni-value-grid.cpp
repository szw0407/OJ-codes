// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2033 lang=cpp
 * @lcpr version=30204
 *
 * [2033] 获取单值网格的最小操作数
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
#include<map>
// @lcpr-template-end
// @lc code=start

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        auto rem = grid[0][0] % x;
        map<int, int> t;
        int sum0 = 0;
        for (auto r : grid) {
            for (auto v : r) {
                if (v % x != rem) return -1;
                t[v/x]++;
                sum0+=v/x;
            }
        }
        int i;
        int l = 0;
        int tot = grid.size()*grid[0].size();
        int tmp = 0;
        int final_sum = sum0;
        for (auto &p : t) {
            auto rt = p.first - tmp;
            sum0 = sum0+rt*l-rt*(tot-l);
            final_sum = min(sum0, final_sum);
            l+=p.second;
            tmp = p.first;
        }
        return final_sum;
        
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=minOperations
// paramTypes= ["number[][]","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [[2,4],[6,8]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[1,5],[2,3]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,4]]\n2\n
// @lcpr case=end

 */

