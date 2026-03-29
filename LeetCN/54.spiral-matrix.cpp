/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=30204
 *
 * [54] 螺旋矩阵
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
    const uint8_t LR = 0;
    const uint8_t TD = 1;
    const uint8_t RL = 2;
    const uint8_t DT = 3;

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        array<int, 4> t = {0,0,0,1};

        uint32_t dir = 0;
        vector<int> res;
        int row = 0;
        int col = 0;
        int visited = 0;
        auto height = matrix.size();
        auto width = matrix[0].size();
        
        while (visited < width * height) {
            res.push_back(matrix[row][col]);
            visited++;
            if (dir % 4 == LR) {
                if (col + 1 + t[LR] == width) {
                    dir++;
                    row++;
                    t[LR]++;
                } else {
                    col++;
                }
            } else if (dir % 4 == TD) {
                if (row + 1 + t[TD] == height) {
                    dir++;
                    col--;
                    t[TD]++;
                } else row++;
            } else if (dir % 4 == RL) {
                if (col - t[RL] == 0) {
                    dir++;
                    row--;
                    t[RL]++;
                } else col--;
            } else {
                if (row - t[DT] == 0) {
                    dir++;
                    col++;
                    t[DT]++;
                } else row--;
            }
        }

        return res;

        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */

