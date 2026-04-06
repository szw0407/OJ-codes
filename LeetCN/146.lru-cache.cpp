/*
 * @lc app=leetcode.cn id=146 lang=cpp
 * @lcpr version=30204
 *
 * [146] LRU 缓存
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
struct Node
{
    Node *next;
    Node *prev;
    int val;
};
class LRUCache
{
public:
    unordered_map<int, Node *> rec;
    int capacity;
    unordered_map<int, int> kvs;
    Node *bg = nullptr;
    Node *ed = nullptr;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (kvs.contains(key))
        {
            auto n = rec[key];
            if (n != bg && n != ed)
            {
                n->prev->next = n->next;
                n->next->prev = n->prev;
                ed ->next = n;
                n->prev = ed;
                ed = n;
            }
            else if (ed == n);
            else
            {
                bg = n->next;
                bg->prev = nullptr;
                ed->next = n;
                n->prev = ed;
                ed = n;
            }
            return kvs[key];
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (kvs.contains(key))
        {
            kvs[key] = value;
            this->get(key);
            return;
        }
        auto s = kvs.size();
        auto n = new Node();
        rec[key] = n;
        n->val = key;
        n->prev = nullptr;
        n->next = nullptr;
        if (s == 0)
        {
            bg = n;
            ed = n;
        }
        else
        {
            ed->next = n;
            n->prev = ed;
            ed = ed->next;
        }

        kvs[key] = value;

        while (kvs.size() > this->capacity)
        {
            rec.erase(bg->val);
            kvs.erase(bg->val);
            bg = bg->next;
            bg->prev = nullptr;
        }
    }
};
int main()
{
    auto lRUCache = LRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    cout << lRUCache.get(1);    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache.get(2);    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache.get(1);    // 返回 -1 (未找到)
    cout << lRUCache.get(3);    // 返回 3
    cout << lRUCache.get(4);
} // 返回 4
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
