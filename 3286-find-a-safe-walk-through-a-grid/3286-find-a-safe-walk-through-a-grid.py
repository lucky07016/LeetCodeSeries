import heapq

class Solution:
    def findSafeWalk(self, grid, health):
        m, n = len(grid), len(grid[0])

        start = health - grid[0][0]
        if start <= 0:
            return False

        heap = [(-start, 0, 0)]
        best = [[-1] * n for _ in range(m)]
        best[0][0] = start

        directions = [(1,0), (-1,0), (0,1), (0,-1)]

        while heap:

            negHealth, r, c = heapq.heappop(heap)
            currHealth = -negHealth

            if r == m - 1 and c == n - 1:
                return True

            if currHealth < best[r][c]:
                continue

            for dr, dc in directions:

                nr = r + dr
                nc = c + dc
                if 0 <= nr < m and 0 <= nc < n:

                    nextHealth = currHealth - grid[nr][nc]
                    if nextHealth > 0 and nextHealth > best[nr][nc]:
                        best[nr][nc] = nextHealth
                        heapq.heappush(heap, (-nextHealth, nr, nc))

        return False