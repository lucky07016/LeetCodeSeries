class Solution:
    def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
        n = len(parent)
        children = [[] for _ in range(n)]
        for i in range(1, n):
            children[parent[i]].append(i)

        newParent = parent[:]
        last = {}

        def dfs(u):
            c = s[u]
            prev = last.get(c, -1)
            if prev != -1:
                newParent[u] = prev
            last[c] = u
            for v in children[u]:
                dfs(v)
            last[c] = prev

        dfs(0)

        g = [[] for _ in range(n)]
        for i in range(1, n):
            g[newParent[i]].append(i)

        size = [1] * n
        order = []
        stack = [0]
        while stack:
            u = stack.pop()
            order.append(u)
            for v in g[u]:
                stack.append(v)

        for u in reversed(order):
            if u != 0:
                size[newParent[u]] += size[u]

        return size