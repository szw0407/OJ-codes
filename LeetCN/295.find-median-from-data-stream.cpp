/*
 * @lc app=leetcode.cn id=295 lang=cpp
 * @lcpr version=30204
 *
 * [295] 数据流的中位数
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
#include <map>
#include <set>
#include <vector>
// @lcpr-template-end
// @lc code=start
class MedianFinder {
multiset<int> nums;
multiset<int>::iterator left, right;
size_t s;
public:
    MedianFinder() {
        s = 0;
    }
    
    void addNum(int num) {
        nums.insert(num);
        s++;
        if (s == 1) {
            left = nums.begin();
            right = left;
        }
        else {
            if (num < *left) {
                if (left == right) {
                    left --;
                } else {
                    right = left;
                }
            } else if (num < *right) {
                right--;
                left++;
            }
            else {
                if (left == right) {
                    right++;
                } else {
                    left = right;
                }
            }
        }
    }
    
    double findMedian() {
        double tmp = 2;
        return (*left+*right)/tmp;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end



