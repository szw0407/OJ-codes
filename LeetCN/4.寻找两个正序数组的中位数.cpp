#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

 // @lc code=start
class Solution {
public:
    int getNthNum(vector<int>& nums1,
        vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;
        int a, b;
        while (1) {
            if (index1 == m) {
                //pass
                return nums2[index2 + k - 1];
            }
            if (index2 == n) {
                // pass

                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                // pass
                return min(nums1[index1], nums2[index2]);
            }
            a = min(index1 + k / 2 - 1, m - 1);
            b = min(index2 + k / 2 - 1, n - 1);
            if (nums1[a] < nums2[b]) {
                k -= a - index1 + 1;
                index1 = a + 1;

            }
            else {
                k -= b - index2 + 1;
                index2 = b + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1,
        vector<int>& nums2) {
        // 本题目可以认为是一个简单的二分答案，每次可以排除掉一半的数据
        auto n = nums1.size() + nums2.size();
        if (n % 2) {
            return getNthNum(nums1, nums2, (n + 1) / 2);
        }
        else {
            return (getNthNum(nums1, nums2, n / 2) + getNthNum(nums1, nums2, n / 2 + 1)) / 2.;
        }
    }


};
// @lc code=end
