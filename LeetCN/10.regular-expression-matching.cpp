// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=10 lang=cpp
 * @lcpr version=30204
 *
 * [10] 正则表达式匹配
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
    bool matchChar(char a, char re){
        return (a == re || re == '.');
    }
    bool isMatch(string s, string p) {
        int sl = s.size();
        int pl = p.size();
        int i,j,k;
        vector<vector<bool> > match(sl+1, vector<bool>(pl+1, false));
        bool cmp_status;
        // 0 means match null str
        // e.g. 'aaa' match 'p*aaa', '' to match 'p*'
        match[0][0] = true;
        // start should be fine.
        for (i=0;i<=sl;i++){

            for (j=1/* '' matches no string */ ; j<=pl;j++){
                // we need to get the match case for 
                if (p[j-1] != '*'){
                    if (i>0)
                    cmp_status = matchChar(s[i-1], p[j-1]) && match[i-1][j-1];
                    else cmp_status = false;
                    match[i][j] = cmp_status;
                } else {
                    // match None
                    if (i>0) cmp_status = matchChar(s[i-1], p[j-2]);
                    else cmp_status = false;
                    match[i][j] = match[i][j-2] || cmp_status && match[i-1][j]; 
                }

                
            }
        }
        return match[sl][pl];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aa"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"a*"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n".*"\n
// @lcpr case=end
 */

