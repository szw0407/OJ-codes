// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 * @lcpr version=30204
 *
 * [25] K 个一组翻转链表
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
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// @lcpr-template-end
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k ==1) return head;
        int m = 0;
        auto anch = new ListNode(0);
        anch ->next = head;
        ListNode* tail, *pre;
        ListNode* tmp;
        int i;
        pre = anch;
        while (head) {
            tail = pre;
            for (i=0;i<k;i++) {
                tail = tail->next;
                if (tail == nullptr) {
                    
                    return anch->next;
                }
            }
            ListNode* next_end = pre->next;

            tmp = tail->next;
            ListNode* a, * b;
            a = pre->next;
            pre->next = tail;

            while (a->next != tail) {
                b = a->next;
                a->next = tmp;
                tmp = a;
                a = b;
                
            }
            a ->next = tmp;
            
            
            head= tail->next;
            tail->next = a;
            pre = next_end; 
        }
        return anch->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */

