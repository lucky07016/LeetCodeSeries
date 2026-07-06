from typing import List, Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:

        indexMap = {value: i for i, value in enumerate(inorder)}
        preorderIndex = 0

        def build(left, right):
            nonlocal preorderIndex

            if left > right:
                return None

            rootValue = preorder[preorderIndex]
            preorderIndex += 1

            root = TreeNode(rootValue)
            mid = indexMap[rootValue]
            root.left = build(left, mid - 1)
            root.right = build(mid + 1, right)

            return root

        return build(0, len(inorder) - 1)