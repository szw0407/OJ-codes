// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30204
 *
 * [15] 三数之和
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
#include <map>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        int i =0;
        int j,k;
        int prev_b;
        int prev_c;
        int prev_a;
        int b_c;
        auto n = nums.size();
        map<int, int> cnts;
        for (i=0;i<n;i++) {
            cnts[nums[i]]++;
        }

        vector<int> keys;
        keys.reserve(cnts.size());
        for (auto const&[k,v]: cnts){
            keys.push_back(k);
        }

        for (i=0;i<keys.size();i++){
            if (cnts[keys[i]] > 1) j = i; else j=i+1;
            prev_a = keys[i];
            
            for (;j<keys.size();j++){
                prev_b = keys[j];
                prev_c = 0 - prev_a - prev_b;
                if (prev_c < prev_b) break;
                auto c = cnts[prev_c];
                if (c) {
                    if (prev_a == prev_b && prev_b == prev_c && c >= 3) {
                        res.push_back({prev_a, prev_b, prev_c});
                    }
                    else if (prev_a != prev_b && prev_b == prev_c && c >=2) {
                        res.push_back({prev_a, prev_b, prev_c});
                    }
                    else if (prev_b != prev_c) {
                        res.push_back({prev_a, prev_b, prev_c});
                    }
                }
            }
        }
        
        // for (i=0;i<n;i++){
        //     if (i!=0 && nums[i]==prev_a) continue;
        //     prev_a = nums[i];
        //     b_c = 0-prev_a;
            
            
            // for (j = i + 1;j<n;j++){
            //     if (j!=i+1 && nums[j] == prev_b) continue;
            //     k = n-1;
            //     prev_b = nums[j];
            //     prev_c = b_c - prev_b;
            //     while (nums[k] > prev_c) {
            //         k--;
            //         if (k <= j) break;
            //     }
            //     if (k <= j) break;
            //     if (prev_c == nums[k]) {
            //         res.push_back({prev_a,
            //             prev_b, 
            //             prev_c});
            //     }

            // }
        // }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */

