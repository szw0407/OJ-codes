// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=30204
 *
 * [22] 括号生成
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
#include <memory>
// #include 
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    unordered_map<int, shared_ptr<vector<string>>> recorded_returned_values;
    shared_ptr<vector<string> > generateMain(int n) {
        if (recorded_returned_values.contains(n)) return recorded_returned_values[n];
        auto ret = std::make_shared<vector<string>>();
        if (n == 0) {
            ret -> push_back("");
            // recorded_returned_values[n] = ret;
            // return ret;
            goto end_part;
        };
        // if (n == 1) {
        //     ret -> push_back("()");
        //     // recorded_returned_values[n] = ret;
        //     // return ret;
        //     goto end_part;
        // }
        int a;
        int b;
        for (a=0;a<n;a++) {
            b = n - a - 1;
            auto av = generateMain(a);
            auto bv = generateMain(b);
            for (auto k : *av) {
                for (auto t : *bv) {
                    ret -> push_back(
                        "(" + k + ")" + t
                    );
                }
            }

        }

    end_part:
        recorded_returned_values[n] = ret;
        return ret;
    }
    vector<string> generateParenthesis(int n) {
        return *generateMain(n);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

