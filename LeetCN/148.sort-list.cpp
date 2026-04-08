// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=148 lang=cpp
 * @lcpr version=30204
 *
 * [148] 排序链表
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    ListNode* sortList(ListNode* head) {
        auto p = head;
        int cnt = 0;
        while (p) {
            p = p->next;
            cnt++;
        }
        if (cnt == 0) return nullptr;

        int i,j;
        
        int sorted_len = 1;
        auto dummyHead = new ListNode();
        dummyHead->next = head;
        while (sorted_len < cnt) {
            auto a = dummyHead->next;
            ListNode* b = nullptr;
            auto t = dummyHead;
            while (a){
                auto head1 = a;
                
                for (i=1;i<sorted_len;i++) {
                    if (!a->next) break;
                    a = a->next;
                }
                
                if (a->next) {
                    b = a->next;
                    a->next = nullptr;
                } else {
                    break;
                }
                auto head2 = b;
                for (i=1;i<sorted_len;i++) {
                    if (!b->next) break;
                    b = b->next;
                }
                ListNode* head3 = nullptr;
                
                head3 = b->next;
                b->next = nullptr;
                
                
                
                while (head1 && head2) {
                    if (head1->val < head2->val) {
                        t->next = head1;
                        head1 = head1->next;
                    } else {
                        t->next = head2;
                        head2 = head2->next;
                    }
                    t = t->next;
                }
                if (head1) t->next = head1;
                else t->next = head2;
                while (t->next) {
                    t = t->next;
                }
                t->next = head3;
                a = head3;
            }
            sorted_len*=2;

        }
        return dummyHead->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,5,3,4,0]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

