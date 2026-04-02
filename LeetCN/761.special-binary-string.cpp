/*
 * @lc app=leetcode.cn id=761 lang=cpp
 * @lcpr version=30204
 *
 * [761] 特殊的二进制字符串
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
    string makeLargestSpecial(string &s, int l, int r) {
        int t = 0;
        int bg = l;
        int ed;
        priority_queue<string> k;
        for (int i=l;i<=r;i++) {
            if (s[i] == '1') t++; else t--;
            if (t == 0) {
                ed = i;
                // bg - ed
                auto _d = makeLargestSpecial(s, bg+1, ed-1);
                k.push(move("1"+_d+"0"));
                bg = ed + 1;
            }
        }
        string res;
        while (k.size())
        {
            res+=k.top();
            k.pop();
        }
        return res;
        

    }
    string makeLargestSpecial(string s) {
        return makeLargestSpecial(s, 0, s.length());
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// "11011000"\n
// @lcpr case=end

// @lcpr case=start
// "10"\n
// @lcpr case=end

 */

