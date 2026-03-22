/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30204
 *
 * [39] 组合总和
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
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    shared_ptr<vector<vector<int> >> main(int lf, int targ, vector<int> &cand) {
        auto res = make_shared<vector<vector<int> > >();

        int i, j;
        for (i=lf;i<cand.size();i++){
            // if (targ < cand[i]) continue;
            // auto rt = new vector<int>();
            auto rt = make_shared<vector<int>>();
            for (j = targ - cand[i];j>=0;j-=cand[i]) {
                rt->push_back(cand[i]);
                if (j == 0) {
                    // conclude the res
                    res->push_back((*rt));
                    
                } else {
                    auto bks = main(i+1,j,cand);
                    for (auto bk : *bks) {
                        // vector<int> t = *rt;
                        // auto t = new vector<int>(*rt);
                        auto t = make_shared<vector<int>>(*rt);
                        t->insert(t->end(), bk.begin(), bk.end());
                        res->push_back((*t));
                    }
                }
            }
        }
        return res;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return *main(0, target, candidates);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

