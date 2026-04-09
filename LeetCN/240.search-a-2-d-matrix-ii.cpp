// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=240 lang=cpp
 * @lcpr version=30204
 *
 * [240] 搜索二维矩阵 II
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto h = matrix.size();
        auto w = matrix[0].size();
        int il = 0;
        int ir = h-1;
        
        int i = 0;
        int j = 0;
        while(ir >= il) {
            i = (ir+il)/2;
            if (matrix[i][0] == target) return true;
            if (matrix[i][0] < target) {
                if (i == h -1 || matrix[i+1][0] > target) break;
                    il = i+1;
            } else {
                ir = i-1;
            }
        };
        if (ir < il) return false;
        i++;
        while(i--){
            int jl = 0;
            int jr = w-1;
            while (1) {
                j = (jr+jl)/2;
                if (matrix[i][j] == target) return true;
                if (matrix[i][j] < target) {
                    if (j == w-1 ||matrix[i][j+1] > target) break;
                    jl = j+1;
                } else {
                    jr = j-1;
                }
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5\n
// @lcpr case=end

// @lcpr case=start
// [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n20\n
// @lcpr case=end

// @lcpr case=start
// [[-1,3]]\n3\n
// @lcpr case=end

 */

