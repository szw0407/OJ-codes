/*
 * @lc app=leetcode.cn id=73 lang=cpp
 * @lcpr version=30204
 *
 * [73] 矩阵置零
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
    void setZeroes(vector<vector<int>>& matrix) {
        int i,j;
        auto h = matrix.size();
        auto w =  matrix[0].size();
        bool firstcol = true;
        for (j=0;j<w;j++) {
            // firstcol
            if (matrix[0][j] == 0) {
                firstcol = false;
                break;
            }
        }

        for (i=0;i<h;i++){
            bool tmp = true;
            for (j=0;j<w;j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    tmp  =false;
                }
                
            }
            if (!tmp && i>=1)
            for (j=0;j<w;j++) {
                matrix[i][j] = 0;
            }
        }
        for (j=0;j<w;j++) {
            if (matrix[0][j] == 0) {
                for (i=0;i<h;i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (!firstcol) {
            for (j=0;j<w;j++) {
                matrix[0][j] = 0;
            }
        }

        // return matrix;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,1],[1,0,1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,2,0],[3,4,5,2],[1,3,1,5]]\n
// @lcpr case=end

 */

