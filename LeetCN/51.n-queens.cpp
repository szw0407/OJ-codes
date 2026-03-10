/*
 * @lc app=leetcode.cn id=51 lang=cpp
 * @lcpr version=30204
 *
 * [51] N 皇后
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
    unordered_set<int> rows = {};
    unordered_set<int> lurd_sums = {};
    unordered_set<int> ldru_sums = {};
    vector<vector<string> > ret = {};
    vector<int> locations = {};
    vector<string> showBoard(int n) {
        vector<string> p;
        string tmp;
        for (auto i : locations) {
            tmp = "";
            for (int j=0;j<n;j++) {
                if (j == i) {
                    tmp += "Q";
                } else {
                    tmp += ".";
                }
            }
            p.push_back(tmp);
        }
        return p;

    }
    void solveMain(int col, int n) {
        if (col == n) {
            ret.push_back(showBoard(n));
            return;
        }
        int i;
        for (i=0;i<n;i++) {
            if (rows.contains(i)) continue;
            if (lurd_sums.contains(i+col)) continue;
            if (ldru_sums.contains(i-col)) continue;

            locations.push_back(i);
            rows.insert(i);
            lurd_sums.insert(i+col);
            ldru_sums.insert(i-col);
            solveMain(col+1, n);
            locations.pop_back();
            rows.erase(i);
            lurd_sums.erase(i+col);
            ldru_sums.erase(i-col);
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        solveMain(0, n);
        return ret;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

