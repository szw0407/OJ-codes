// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=739 lang=cpp
 * @lcpr version=30204
 *
 * [739] 每日温度
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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        auto ret = vector<int>(temperatures.size(), 0);
        auto st = vector<int>();
        // int curr_max = INT_MIN;
        // st.push_back({INT_MIN,INT_MAX});
        int i;
        for (i=0;i<temperatures.size();i++) {

                

            while (!st.empty()&&temperatures[i] > temperatures[st.back()]) {
                ret[st.back()] = i - st.back();
                st.pop_back();
            }
            st.push_back(i);
        }
        return ret;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [73,74,75,71,69,72,76,73]\n
// @lcpr case=end

// @lcpr case=start
// [30,40,50,60]\n
// @lcpr case=end

// @lcpr case=start
// [30,60,90]\n
// @lcpr case=end

 */

