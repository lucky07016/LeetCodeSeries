from typing import List

class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:

        parent = list(range(n))

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(a, b):
            pa = find(a)
            pb = find(b)
            if pa != pb:
                parent[pa] = pb
        for i in range(n - 1):
            if nums[i + 1] - nums[i] <= maxDiff:
                union(i, i + 1)

        ans = []
        for u, v in queries:
            ans.append(find(u) == find(v))

        return ans