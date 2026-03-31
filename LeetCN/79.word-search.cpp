// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=79 lang=cpp
 * @lcpr version=30204
 *
 * [79] 单词搜索
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
    int h,w;
    bool found(vector<vector<char>>& board, string &word, int c, vector<vector<bool> > &visited, int i, int j) {
        if (visited[i][j]) return false;
        if (board[i][j] != word[c]) return false;
        visited[i][j] = true;
        c++;
        if (c == word.length()) return true;
        if (i > 0 && found(board, word, c, visited, i-1, j)) return true;
        if (j > 0 && found(board, word, c, visited, i, j-1)) return true;
        if (i < h-1 && found(board, word, c, visited, i+1, j)) return true;
        if (j < w-1 && found(board, word, c, visited, i, j+1)) return true;
        visited[i][j] = false;
        return false;
    };
    bool exist(vector<vector<char>>& board, string word) {
        int i,j;
        h = board.size();
        if (!h) return false;
        w = board[0].size();
        if (!w) return false;
        int cnt = 0;
        // bool finding = false;
        auto visited = vector<vector<bool> >(h, vector<bool>(w, false));
        bool res;
        for (i=0;i<h;i++) {
            for (j=0;j<w;j++) {
                if (found(
                    board, word, 0, visited, i, j
                )) return true;
                
                }
            }
            return false;
        }
        
    
};
// @lc code=end



/*
// @lcpr case=start
// [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]\n"ABCCED"\n
// @lcpr case=end

// @lcpr case=start
// [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [["C","A","A"],["A","A","A"],["B","C","D"]]\n"AAB"\n
// @lcpr case=end

 */

