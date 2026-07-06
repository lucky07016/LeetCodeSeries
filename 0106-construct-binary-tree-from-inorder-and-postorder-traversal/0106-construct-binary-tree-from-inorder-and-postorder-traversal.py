from typing import List, Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:

        indexMap = {value: i for i, value in enumerate(inorder)}
        postIndex = len(postorder) - 1

        def build(left, right):
            nonlocal postIndex

            if left > right:
                return None

            rootValue = postorder[postIndex]
            postIndex -= 1

            root = TreeNode(rootValue)
            mid = indexMap[rootValue]
            root.right = build(mid + 1, right)
            root.left = build(left, mid - 1)

            return root

        return build(0, len(inorder) - 1) 