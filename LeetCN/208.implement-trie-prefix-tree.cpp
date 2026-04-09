/*
 * @lc app=leetcode.cn id=208 lang=cpp
 * @lcpr version=30204
 *
 * [208] 实现 Trie (前缀树)
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
struct Node {
    Node* parent;
    vector<Node*> sons;
    char c;
};
class Trie {
public:

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        auto t = word.length();
        int i;
        Node* p = this->root;
        for (i=0;i<t;i++){
            auto found=false;
            Node* k = nullptr;
            for (auto _k : p->sons) {
                if (_k->c == word[i]) {found=true;k = _k;break;}
            }
            if (!found) {
                auto _new = new Node();
                _new->c = word[i];
                _new->parent = p;
                p->sons.push_back(_new);
                p = _new;
            } else {
                p = k;
            }
            
        }
        ends.insert(p);

    }
    
    bool search(string word) {
        auto t = word.length();
        int i;
        Node* p = this->root;
        for (i=0;i<t;i++) {
            
            Node* k = nullptr;
            for (auto _k : p->sons) {
                if (_k->c == word[i]) {k = _k;break;}
            }
            if (!k) {
                return false;
            }
            p = k;

        }
        return (ends.contains(p));
    }
    
    bool startsWith(string prefix) {
                auto t = prefix.length();
        int i;
        Node* p = this->root;
        for (i=0;i<t;i++) {
            
            Node* k = nullptr;
            for (auto _k : p->sons) {
                if (_k->c == prefix[i]) {k = _k;break;}
            }
            if (!k) {
                return false;
            }
            p = k;

        }
        return true;
    }
private:
    unordered_set<Node*> ends;
    Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end



