# 98-valid-binary-tree.cpp;bt-recusion;help;leetcode

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        previous = [None]

        def inorder(node):
            if node is None:
                return True
            if not inorder(node.left):
                return False
            if previous[0] is not None and node.val <= previous[0]:
                return False
            previous[0] = node.val

            return inorder(node.right)

        return inorder(root)