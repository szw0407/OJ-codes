#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ord;
        vector<int> res;
        int i;
        int tmp;
        for (i=0;i<nums.size();i++){
            ord[nums[i]] = i;
        }
        for (i=0;i<nums.size();i++){
           if ( ord.count(target-nums[i])){
            tmp = ord[target-nums[i]];
            if (tmp == i) {
                continue;
            }
            res.push_back(i);
            res.push_back(tmp);
            break;
           }
        }
        return res;
    }
};
// @lc code=end

