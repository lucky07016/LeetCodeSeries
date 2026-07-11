from collections import defaultdict

class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = defaultdict(list)

        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        visited = [False] * n
        answer = 0

        def dfs(node):
            visited[node] = True
            vertices = 1
            degree_sum = len(graph[node])

            for nei in graph[node]:
                if not visited[nei]:
                    v, d = dfs(nei)
                    vertices += v
                    degree_sum += d

            return vertices, degree_sum

        for i in range(n):
            if not visited[i]:
                vertices, degree_sum = dfs(i)
                edges_count = degree_sum // 2

                if edges_count == vertices * (vertices - 1) // 2:
                    answer += 1

        return answer