/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=30204
 *
 * [76] 最小覆盖子串
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
    string minWindow(string s, string t) {
        unordered_map<char, int> od;
        unordered_map<char, int> td;
        int min_len = INT_MAX;
        for (auto ch:t) {
            td[ch]++;
        }
        queue<int> q;
        bool status = false;
        string ans = "";
        char next_seek = NULL;
        for (int i=0;i<s.size();i++) {
            char ch  = s[i];
            // if (status){ // to seek for the 1st match
            if (td.contains(ch)) {
                // related
                od[ch]++;
                q.push(i);
                bool tmp = true;
                if (status) {
                    if (ch == next_seek) {
                        ;
                    } else continue;
                } else 
                {
                for (auto d:td) {
                    if (td[d.first]>od[d.first]) {
                        tmp = false;
                        break;
                    }
                }}
                
                if (tmp) {
                    // complete
                    unsigned int f;

                    while (1) {
                        f = q.front();
                        if (td[s[f]] > od[s[f]] -1) break;
                        else {
                            q.pop();
                            od[s[f]]--;
                            // remove duplicated unnecessary front chars
                        }
                    }
                    next_seek = s[f];

                    if (i-f+1 < ans.length() || ans.length() == 0)
                    ans = s.substr(f, i-f+1);

                    

                }
            // }
            }
        }

        return ans;

        
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */

