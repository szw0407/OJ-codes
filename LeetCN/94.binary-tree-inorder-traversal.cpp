/*
 * @lc app=leetcode.cn id=94 lang=cpp
 * @lcpr version=30204
 *
 * [94] 二叉树的中序遍历
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        auto curr = root;
        auto prev = curr;
        while (prev)
        {
            if (prev->left) {
                curr = prev->left;
                while (curr->right && curr->right != prev) {
                    curr = curr->right;
                }
                if (curr->right == nullptr){
                    curr->right = prev;
                    prev = prev -> left;
                } else {
                    // nothing is on left
                    res.push_back(prev->val);
                    curr->right = nullptr; // no loop
                    prev = prev->right;  // back to top parent
                }
            }
            
            else {
                res.push_back(prev->val);
                // curr->right = nullptr;
                prev = prev->right;

            }
        }
        
            
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

