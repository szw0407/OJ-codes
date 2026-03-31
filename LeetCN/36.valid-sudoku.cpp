// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=36 lang=cpp
 * @lcpr version=30204
 *
 * [36] 有效的数独
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
    bool isValidSudoku(vector<vector<char>>& board) {
        int i,j;
        
        for (i=0;i<9;i++) {
            auto t = new vector<bool>(500, false);
            for (j=0;j<9;j++) {
                if (board[i][j] == '.') continue;
                if(t->at(board[i][j])) 
                return false;
                t->at(board[i][j])=true;
            }
            delete t;
        }        
        for (i=0;i<9;i++) {
            auto t = new vector<bool>(500, false);
            for (j=0;j<9;j++) {
                if (board[j][i] == '.') continue;
                if(t->at(board[j][i])) 
                return false;
                t->at(board[j][i]) = true;
            }
            delete t;
        }
        for (i=0;i<9;i+=3) {
            for (j=0;j<9;j+=3) {
                auto t = new vector<bool>(500, false);
                for (int x=i;x<i+3;x++) {
                    for (int y=j;y<j+3;y++) {
                        if (board[x][y] == '.') continue;
                        if(t->at(board[x][y])) 
                        return false;
                        t->at(board[x][y]) = true;
                    }
                }
                delete t;
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

// @lcpr case=start
// [["8","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */

