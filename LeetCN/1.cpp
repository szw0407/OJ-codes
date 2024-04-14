#include<bits/stdc++.h>
using namespace std; // namespace std;
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
            res.push_back(tmp);
            res.push_back(i);
            break;
           }
        }
        return res;
    }
};
