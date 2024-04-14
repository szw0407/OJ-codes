#include<bits/stdc++.h> 
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto n1 = *l1;
        auto n2 = *l2;
        int val = (n1.val+n2.val)%10;
        bool inc = n1.val+n2.val>=10;

        auto ret = new ListNode(val);
        auto itm = ret;
        int a,b;
        while (n1.next != nullptr || n2.next != nullptr) {
            if (n1.next == nullptr) {
                a=0;
            } else
            {n1=*n1.next;
            a=n1.val;}
            if (n2.next == nullptr) {
                b=0;
            } else 
            {n2=*n2.next;b=n2.val;}
            // val = n1.val+n2.val;
            val=a+b;
            if (inc) val++;
            if (val>=10) {
                val = val % 10;
                inc = true;
            } else inc = false;
            itm->next = new ListNode(val);
            itm = itm->next;
        }
        if (inc){
            itm->next = new ListNode(1);
        }
        return ret;
    }
};

int main(){

    return 0;
}