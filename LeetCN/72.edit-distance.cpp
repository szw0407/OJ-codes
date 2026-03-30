// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=72 lang=cpp
 * @lcpr version=30204
 *
 * [72] 编辑距离
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
    int minDistance(string word1, string word2) {
        
        auto l1 = word1.length();
        auto l2 = word2.length();

        auto d  = vector<vector<int> >(l1+1, vector<int>(l2+1, 0));

        int i,j;
        for (j=1;j<=l2;j++) {
            d[0][j] = j;
        }
        for (i=1;i<=l1;i++) {
            d[i][0] = i;
        }
        for (i=1;i<=l1;i++) {
            for (j=1;j<=l2;j++) {
                if (word1[i-1] ==  word2[j-1] ) {
                    d[i][j] = d[i-1][j-1];
                } else {
                    // switch current char
                    d[i][j] = d[i-1][j-1]+1;
                }
                d[i][j] = min(d[i-1][j]+1, d[i][j]);
                d[i][j] = min(d[i][j-1]+1, d[i][j]);

            }
        }
        return d[l1][l2];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "horse"\n"ros"\n
// @lcpr case=end

// @lcpr case=start
// "intention"\n"execution"\n
// @lcpr case=end

 */

