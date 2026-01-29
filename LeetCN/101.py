# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:

        def cmp(l: Optional[TreeNode], r:Optional[TreeNode]):
            if isinstance(l, TreeNode) and isinstance(r, TreeNode) and l.val == r.val:
                # return True 
                return cmp(l.right, r.left) and cmp(l.left, r.right)
            elif l is None and r is None:
                return True
            else:
                return False
            
        return cmp(root.left, root.right)

        