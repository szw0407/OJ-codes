// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=43 lang=cpp
 * @lcpr version=30204
 *
 * [43] 字符串相乘
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
#include <math.h>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        auto n1 = num1.size();
        auto n2 = num2.size();
        int i,j;
        string res = "";
        auto r = new vector<int>(n1+n2, 0);
        for (i=n1-1;i>=0;i--) {
            for (j=n2-1;j>=0;j--) {
                r->at(n1-i+n2-j-2) += (num1[i] - '0') * (num2[j] - '0');
                
            }
        }
        int rem = 0;
        for (i = 0;i<n1+n2-1;i++) {
            // if (r->at(i) + rem == 0 && i > 0) break;
            char z =( (r->at(i) + rem) % 10 + '0');
            res = z + res;
            rem = (r->at(i) + rem) / 10;



        }
        if (rem) {
            char z =( (r->at(i) + rem) % 10 + '0');
            res = z + res;
            rem = (r->at(i) + rem) / 10;
        }
        return res;
       
    }
};
// @lc code=end



/*
// @lcpr case=start
// "2"\n"3"\n
// @lcpr case=end

// @lcpr case=start
// "123"\n"456"\n
// @lcpr case=end

 */

