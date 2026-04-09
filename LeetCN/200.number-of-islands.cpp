// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=200 lang=cpp
 * @lcpr version=30204
 *
 * [200] 岛屿数量
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
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        auto visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        int res = 0;
        int i, j;
        auto q = queue<pair<int, int> >();
        for (i = 0; i < grid.size(); i++)
        {
            for (j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    res++;
                    q.push({i, j});
                    visited[i][j] = true;
                    while (!q.empty())
                    {
                        auto _n = new int(q.size());
                        for (auto k = 0;k<*_n;k++) {
                            auto tmp = q.front();
                            q.pop();
                            
                            if (tmp.first > 0 && grid[tmp.first-1][tmp.second] == '1' && !visited[tmp.first-1][tmp.second]) {
                                q.push({tmp.first-1, tmp.second});
                                visited[tmp.first-1][tmp.second] = true;
                            }
                            if (tmp.first < grid.size() -1 && grid[tmp.first+1][tmp.second] == '1' && !visited[tmp.first+1][tmp.second]) {
                                q.push({tmp.first+1, tmp.second});
                                visited[tmp.first+1][tmp.second] = true;
                            }
                            if (tmp.second > 0 && grid[tmp.first][tmp.second-1] == '1' && !visited[tmp.first][tmp.second-1]) {
                                q.push({tmp.first, tmp.second-1});
                                visited[tmp.first][tmp.second-1] = true;
                            }
                            if (tmp.second < grid[0].size()-1 && grid[tmp.first][tmp.second+1] == '1' && !visited[tmp.first][tmp.second+1]) {
                                q.push({tmp.first, tmp.second+1});
                                visited[tmp.first][tmp.second+1] = true;
                            }
                        }
                    }
                    
                }
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["1","1","1","1","1","0","1","1","1","1"],["1","0","1","0","1","1","1","1","1","1"],["0","1","1","1","0","1","1","1","1","1"],["1","1","0","1","1","0","0","0","0","1"],["1","0","1","0","1","0","0","1","0","1"],["1","0","0","1","1","1","0","1","0","0"],["0","0","1","0","0","1","1","1","1","0"],["1","0","1","1","1","0","0","1","1","1"],["1","1","1","1","1","1","1","1","0","1"],["1","0","1","1","1","1","1","1","1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]\n
// @lcpr case=end

 */
