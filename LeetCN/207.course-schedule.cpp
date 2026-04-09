/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * @lcpr version=30204
 *
 * [207] 课程表
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
    vector<int> cache;
    bool trace(vector<vector<int > > &parents, vector<bool> &visited, int id) {
        if (cache[id]) {
            if (cache[id] == 1) return true;
            return false;
        }
        if (visited.at(id)){cache[id] = 1; return true;}
        visited[id] = true;
        for (auto p : parents[id]) {
            if (trace(parents, visited, p))
            {cache[id] = 1;
            return true;}
        }
        visited[id] = false;
        cache[id] = -1;
        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        cache = vector<int>(numCourses, NULL);
        auto parents = vector<vector<int> >(numCourses, vector<int>());
        auto visited = vector<bool>(numCourses, false);
        for (auto p : prerequisites) {
            parents[p[0]].push_back(p[1]);
        }
        for (int k = 0;k<numCourses;k++) {
            if (trace(parents, visited, k)) return false;
        }
        return true;

    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

 */

