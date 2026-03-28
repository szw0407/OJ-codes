/*
 * @lc app=leetcode.cn id=49 lang=cpp
 * @lcpr version=30204
 *
 * [49] 字母异位词分组
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
struct HASH {
        std::size_t operator()(const std::array<int, 26>& arr) const {
            std::size_t seed = 0; // 局部变量
            for (auto x : arr) {
                seed ^= std::hash<int>{}(x) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };
    

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, int, HASH> groupMap;
        vector<vector<string>> res;

        for (const auto& s : strs) {
            array<int, 26> cnt = {0};
            for (char c : s) {
                cnt[c - 'a']++;
            }

            auto it = groupMap.find(cnt);
            if (it != groupMap.end()) {
                res[it->second].emplace_back(s);
            } else {
                groupMap[cnt] = res.size();
                res.emplace_back(vector<string>{s});
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["eat", "tea", "tan", "ate", "nat", "bat"]\n
// @lcpr case=end

// @lcpr case=start
// [""]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

 */

