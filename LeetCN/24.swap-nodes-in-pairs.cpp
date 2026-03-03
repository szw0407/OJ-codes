// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=30204
 *
 * [24] 两两交换链表中的节点
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
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head)
            return head;
        auto new_head = head->next;
        if (!new_head)
            return head; // only one element
        auto next_pair = new_head->next;
        new_head->next = head;
        ListNode *b;
        auto a = new_head->next;
        // a->next = next_pair;
        a->next = nullptr;
        while (next_pair)
        {
            b = next_pair->next;

            
            if (b)
            {
                a->next = b;
                a = next_pair;
                a->next = nullptr;
                next_pair = b->next;
                b->next = a;
            }
            else{
                a->next = next_pair;
                break;
            }
        }
        return new_head;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
