# 114-flattern-bt-to-ll.py;ll;help;leetcode

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def flatten(self, root: TreeNode | None) -> None:
        if root is None:
            return

        self.flatten(root.left)
        self.flatten(root.right)

        right_subtree = root.right

        root.right = root.left
        root.left = None

        curr = root

        while curr.right is not None:
            curr = curr.right

        curr.right = right_subtree