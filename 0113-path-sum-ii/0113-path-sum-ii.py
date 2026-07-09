# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def pathSum(self, root, targetSum):

        ans = []

        def dfs(node, remaining, path):

            if not node:
                return

            path.append(node.val)
            remaining -= node.val

            if not node.left and not node.right and remaining == 0:
                ans.append(path[:])

            dfs(node.left, remaining, path)
            dfs(node.right, remaining, path)

            path.pop()

        dfs(root, targetSum, [])

        return ans