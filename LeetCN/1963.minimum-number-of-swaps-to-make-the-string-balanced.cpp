/*
 * @lc app=leetcode.cn id=1963 lang=cpp
 * @lcpr version=30204
 *
 * [1963] 使字符串平衡的最小交换次数
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
    int minSwaps(string s) {
        // vector<int> lpos = {};
        // vector<int> rpos = {};
        int l = 0;
        int r = 0;
        int i;
        int len = s.size();
        for (i=0;i<len;i++) {
            if (s[i] == '[') {
                // lpos.push_back(i);
                l++;
            }
            else {
                if (l) {
                    l--;
                } else {
                    r++;
                }
            }
        }
        if (l % 2 == 0) return l/2;
        return l/2+1;
        // int res = 0;
        // for (int t = 0;t<lpos.size();t++) {
        //     res+=lpos[t] - rpos[t] - t;
        // }
        
    }
    
};
// @lc code=end



/*
// @lcpr case=start
// "][]["\n
// @lcpr case=end

// @lcpr case=start
// "]]][[["\n
// @lcpr case=end

// @lcpr case=start
// "[]"\n
// @lcpr case=end

 */

