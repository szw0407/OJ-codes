// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=102 lang=cpp
 * @lcpr version=30204
 *
 * [102] 二叉树的层序遍历
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
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        
        TreeNode* p = root;
        if (!p) return {};
        int h = 0;
        TreeNode* next_line_first = p;
        bool need_update = false;

        // vector<int> l;
        // auto l = new vector<int>();
        std::vector<int> *l = nullptr;
        vector<vector<int> > ret;
        q.push(p);
        // l->push_back(p->val);
        // if (p->left) next_line_first = p->left;
        // else if (p->right) next_line_first = p->right;
        // else return {{p->val}};
        while (q.size()) {
            
            if (p == next_line_first) {
                need_update = true; // next line first is to be updated.
                if (l)
                ret.push_back(*l);
                l = new vector<int>();
                
            }
            l->push_back(p->val);
            if (p->left){ q.push(p->left);
            if (need_update) {
                need_update = false;
                next_line_first = p->left;
            }}
            if (p->right) {q.push(p->right);
            if (need_update) {
                need_update = false;
                next_line_first = p->right;
            }}
            q.pop();
            p = q.front();
            
            
        }
        ret.push_back(*l);
        return ret;
    }

};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

