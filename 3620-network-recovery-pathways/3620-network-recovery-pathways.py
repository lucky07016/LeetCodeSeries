from typing import List
from collections import deque

class Solution:
    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        n = len(online)

        graph = [[] for _ in range(n)]
        indegree = [0] * n
        maxCost = 0

        for u, v, c in edges:
            graph[u].append((v, c))
            indegree[v] += 1
            maxCost = max(maxCost, c)

        # Topological Order
        q = deque()

        indeg = indegree[:]
        topo = []

        for i in range(n):
            if indeg[i] == 0:
                q.append(i)

        while q:
            u = q.popleft()
            topo.append(u)

            for v, _ in graph[u]:
                indeg[v] -= 1
                if indeg[v] == 0:
                    q.append(v)

        INF = float("inf")

        def check(limit):
            dist = [INF] * n
            dist[0] = 0

            for u in topo:
                if dist[u] == INF:
                    continue

                if u != 0 and u != n - 1 and not online[u]:
                    continue

                for v, cost in graph[u]:

                    if cost < limit:
                        continue

                    if v != n - 1 and not online[v]:
                        continue

                    if dist[u] + cost < dist[v]:
                        dist[v] = dist[u] + cost

            return dist[n - 1] <= k

        lo = 0
        hi = maxCost
        ans = -1

        while lo <= hi:
            mid = (lo + hi) // 2

            if check(mid):
                ans = mid
                lo = mid + 1
            else:
                hi = mid - 1

        return ans