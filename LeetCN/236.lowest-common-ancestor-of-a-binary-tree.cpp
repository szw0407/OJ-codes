/*
 * @lc app=leetcode.cn id=236 lang=cpp
 * @lcpr version=30204
 *
 * [236] 二叉树的最近公共祖先
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lcpr-template-end
// @lc code=start

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
unordered_map<TreeNode *, TreeNode*> fathers;
void dfs(TreeNode * n) {
    if (n == nullptr) return;
    if (n->left)
    {fathers[n->left] = n;dfs(n->left);}
    if (n->right)
    {fathers[n->right] = n;
    
    dfs(n->right);}
}
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fathers[root] = nullptr;
        dfs(root);
        unordered_set<TreeNode *> father_a;
        auto a = p;
        while (1) {
            father_a.insert(a);
            a = fathers[a];
            if (a == nullptr) break;
        }
        auto b = q;
        while (1) {
            if (father_a.contains(b)) {
                break;
            }
            b = fathers[b];
        }
        return b;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n2\n
// @lcpr case=end

 */

