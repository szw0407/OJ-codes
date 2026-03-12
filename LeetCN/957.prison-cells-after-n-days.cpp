/*
 * @lc app=leetcode.cn id=957 lang=cpp
 * @lcpr version=30204
 *
 * [957] N 天后的牢房
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
#include <vector>
#include <map>

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        map<vector<int>, int> seen;
        // vector<vector<int>> history;
        
        seen[cells] = 0;
        // history.push_back(cells);
        
        int size = cells.size();
        
        for (int i = 1; i <= n; ++i) {
            vector<int> next_cells(size, 0);
            
            for (int j = 1; j < size - 1; ++j) {
                next_cells[j] =( cells[j - 1] == cells[j + 1])?1:0;
            }
            
            cells = next_cells;
            
            if (seen.contains(cells)) {
                int k = seen[cells];       
                int cycle_len = i - k;     
                int remaining = n - i;     
                for (int i = 0;i<remaining % cycle_len;i++) {
                    vector<int> next_cells(size, 0);
                    for (int j = 1; j < size - 1; ++j) {
                next_cells[j] =( cells[j - 1] == cells[j + 1])?1:0;
            }
                cells = next_cells;
                }
                break;
                // return history[k + (remaining % cycle_len)];
            }
            
            seen[cells] = i;
            // history.push_back(cells);
        }
        
        return cells;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,1,1,0,0,1]\n7\n
// @lcpr case=end

// @lcpr case=start
// [1,0,0,1,0,0,1,0]\n1000000000\n
// @lcpr case=end

 */

