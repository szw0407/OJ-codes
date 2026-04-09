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
class Trie {
public:

    Trie() {
        
    }
    
    void insert(string word) {
        storage.insert(word);
        auto t = word.length();
        for (int i = 1;i<=t;i++) {
            auto k = word.substr(0, i);
            pref_cache.insert(k);
        }
    }
    
    bool search(string word) {
        return storage.contains(word);
    }
    
    bool startsWith(string prefix) {
        return pref_cache.contains(prefix);
    }
private:
    unordered_set<string> pref_cache;
    unordered_set<string> storage;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end



