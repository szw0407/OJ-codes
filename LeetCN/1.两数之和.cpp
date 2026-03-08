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
        unordered_map<int, vector<int>> k = {};
        int i = 0;
        vector<int> res;
        for (i=0;i<nums.size();i++){
            //k[nums[i]] ;
            if (k.find(nums[i]) == k.end()){
                k[nums[i]] = {i};
            } else {
                k[nums[i]].push_back(i);
            }
        }
        for (auto &j:nums){
            if (target - j == j){
                if (k[j].size() > 1) {
                    res = {k[j][0], k[j][1]};
                    return res;
                } else continue;
            }
            if (k.find(target - j) == k.end()){
                ;
            } else {
                
                res = {k[j][0], k[target - j][0]};
                return res;
            }
        }
        return res;
    }
};
// @lc code=end

