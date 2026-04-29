// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1106 lang=cpp
 * @lcpr version=30204
 *
 * [1106] 解析布尔表达式
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
    bool parseBoolExpr(string expression) {
        if (expression == "f") return false;
        if (expression == "t") return true;
        if (expression[0] == '!') {
            return !parseBoolExpr(expression.substr(2, expression.length()-3));
        }
        int i = 2;
        int j = i;
        int d = 0;
        bool k = expression[0] == '&';
        for (;j<expression.length();j++) {
            
            if (expression[j] == '(') d++;
            if (expression[j] == ')') d--;
            if (expression[j] == ',' && d == 0 || d == -1) {
                if (expression[0] == '&')
                k = k && parseBoolExpr(expression.substr(i, j-i));
                else 
                k = k || parseBoolExpr(expression.substr(i, j-i));
                i = j+1;
            }
        }
        return k;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// "&(|(f))"\n
// @lcpr case=end

// @lcpr case=start
// "|(f,f,f,t)"\n
// @lcpr case=end

// @lcpr case=start
// "!(&(f,t))"\n
// @lcpr case=end

 */

