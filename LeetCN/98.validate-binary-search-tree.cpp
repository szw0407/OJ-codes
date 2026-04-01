/*
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=30204
 *
 * [98] 验证二叉搜索树
 */


// @lcpr-template-start
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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
    tuple<bool, int, int> validate(TreeNode* n) {
        // if (!n->left && ! n->right) return {true, n->val, n->val};
        // if (n->left && n->left->val >= n->val) return {false, NULL, NULL};
        // if (n->right && n->right->val <= n->val) return {false, NULL, NULL};
        int max_val = n->val;
        int min_val = n->val;
        if (n->left) {
            auto t = validate(n->left);
            if (!std::get<0>(t)) return {false, NULL, NULL};
            if (std::get<2>(t) >= n->val) return {false, NULL, NULL};
            min_val = std::get<1>(t);
        }
        if (n->right) {
            auto t = validate(n->right);
            if (!std::get<0>(t)) return {false, NULL, NULL};
            if (std::get<1>(t) <= n->val) return {false, NULL, NULL};
            max_val = std::get<2>(t);
        }
        return {true, min_val, max_val};
    }
    bool isValidBST(TreeNode* root) {
        return std::get<0>(validate(root));
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */

