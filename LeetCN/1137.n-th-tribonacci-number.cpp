// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 * @lcpr version=30204
 *
 * [1137] 第 N 个泰波那契数
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
    int tribonacci(int n) {
        size_t a = 0;
        size_t b = 1;
        size_t c = 1;
        size_t i = 0;
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        for (;i<n;i++) {
            auto nxt = a+b+c;
            a = b;
            b = c;
            c = nxt;
        }
        return a;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=tribonacci
// paramTypes= ["number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 25\n
// @lcpr case=end

 */

