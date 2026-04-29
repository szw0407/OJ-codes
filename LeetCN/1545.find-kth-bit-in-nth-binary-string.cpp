/*
 * @lc app=leetcode.cn id=1545 lang=cpp
 * @lcpr version=30204
 *
 * [1545] 找出第 N 个二进制字符串中的第 K 位
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
    string reverse(string s) {
        string tmp;
        for (int i = s.size()-1;i>=0;i--) {
            tmp+=s[i];
        }
        return tmp;
    }
    string invert(string &s) {
        for (int i=0;i<s.length();i++) {
            if (s[i] == '0') {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }
        return s;
    }
    string nxt(string prev) {
        return prev+"1"+reverse(invert(prev));
    }
    char findKthBit(int n, int k) {
        string tmp  = "0";
        for (int i=0;i<n;i++) {
            tmp = nxt(tmp);
        }
        return tmp[k-1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n1\n
// @lcpr case=end

// @lcpr case=start
// 4\n11\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

// @lcpr case=start
// 2\n3\n
// @lcpr case=end

 */

