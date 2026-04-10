// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=394 lang=cpp
 * @lcpr version=30204
 *
 * [394] 字符串解码
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
    string decodeString(string s) {
        string res;
        vector<string> vs;
        vector<int> vi;
        int num = 1;
        string current_s = "";
        for (int i = 0;i<s.size();i++) {
            char c = s[i];
            if (c <= 'z' && c >= 'a') {
                current_s+=c;
            } else if (c <= '9' && c >= '0')
            {
                if (i == 0 || s[i-1] < '0' || s[i-1] > '9'){
                    vi.push_back(num);
                    num = c - '0';
                    vs.push_back(current_s);
                
                    current_s = "";
                } else
                {num *= 10;
                num += c - '0';}
            } else if (c == '[') {
                ;
                
            } else if (c == ']') {
                string tmp;
                while (num--) {
                    tmp += current_s;
                }
                if (vs.size()) {
                    current_s = vs.back() + tmp;
                    vs.pop_back();
                    num = vi.back();
                    vi.pop_back();
                }
            }
            
        }
        return current_s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "100[leetcode]"
// @lcpr case=end

// @lcpr case=start
// "3[a2[c]]"\n
// @lcpr case=end

// @lcpr case=start
// "2[abc]3[cd]ef"\n
// @lcpr case=end

// @lcpr case=start
// "abc3[cd]xyz"\n
// @lcpr case=end

 */

