// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=155 lang=cpp
 * @lcpr version=30204
 *
 * [155] 最小栈
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
class MinStack {
public:
    map<int, int> bucket;
    vector<int> items;
    int min_val = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        bucket[val]++;
        items.push_back(val);
        if (val < min_val) min_val = val;
    }
    
    void pop() {
        auto tmp = items.back();
        bucket[tmp]--;
        if (bucket[tmp] == 0) {
            bucket.erase(tmp);
            if (min_val == tmp) {
                if (bucket.size())
                for (auto &[k, v] : bucket) {
                    min_val = k;
                    break;
                } else {
                    min_val = INT_MAX;
                }
            }
        }
        items.pop_back();
        
    }
    
    int top() {
        return items.back();
    }
    
    int getMin() {
        return min_val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]\n[[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]
// @lcpr case=end

 */

