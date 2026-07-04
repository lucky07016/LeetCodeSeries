from collections import defaultdict

class Solution:
    def minScore(self, n: int, roads: list[list[int]]) -> int:

        graph = defaultdict(list)

        for u, v, d in roads:
            graph[u].append((v, d))
            graph[v].append((u, d))

        visited = set()
        answer = float('inf')

        def dfs(node):
            nonlocal answer

            visited.add(node)

            for nxt, dist in graph[node]:
                answer = min(answer, dist)
                if nxt not in visited:
                    dfs(nxt)

        dfs(1)
        return answer