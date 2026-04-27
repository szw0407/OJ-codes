// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=93 lang=cpp
 * @lcpr version=30204
 *
 * [93] 复原 IP 地址
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
    vector<string> res;
    string parseIPAddr(vector<string> c) {
        string res = "";
        for (int i=0;i<3;i++) {
            res+=c[i];
            res+=".";
        }
        res+=c[3];
        return res;
    }
    void checkIP(string s, vector<string> &c, string current_num, int i) {
        if (i == s.length()) {
            if (c.size() == 4 && current_num == "")
            res.push_back(parseIPAddr(c));
            return;
        }
        
        if (c.size()<4) {
            auto tmp = current_num+s[i];
            if (tmp[0]!='0'&&tmp.length()<=2) {
                checkIP(s, c, tmp, i+1);
            }
            if (tmp.size()>3 ||tmp.length()==3&& tmp>"255") {
                tmp;
            } else {
                c.push_back(tmp);
                checkIP(s, c, "", i+1);
                c.pop_back();
            }
        }

    }
    vector<string> restoreIpAddresses(string s) {
        auto c  =vector<string>();
        checkIP(s, c, "", 0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "25525511135"\n
// @lcpr case=end

// @lcpr case=start
// "0000"\n
// @lcpr case=end

// @lcpr case=start
// "101023"\n
// @lcpr case=end

 */

