// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=124 lang=cpp
 * @lcpr version=30204
 *
 * [124] 二叉树中的最大路径和
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
// class TreeNodeData {
//     int l_max_sum;
//     int r_max_sum;
//     bool visited;
// };
class Solution {
public:
    int max_sum = INT_MIN;
    int dfs(TreeNode* n) {
        if (!n) return 0;
        int l_max = 0;
        int r_max = 0;

        l_max = dfs(n->left);
        r_max = dfs(n->right);
        int tmp = n->val;
        auto res = max(tmp, tmp+max(l_max, r_max));
        if (l_max > 0) tmp += l_max;
        if (r_max > 0) tmp += r_max;
        max_sum = max(tmp, max_sum);
        return res;
    }
    int maxPathSum(TreeNode* root) {
        // unordered_map<TreeNode*, TreeNodeData> s;
        auto _ = dfs(root);
        return max_sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-10,9,20,null,null,15,7]\n
// @lcpr case=end

 */

