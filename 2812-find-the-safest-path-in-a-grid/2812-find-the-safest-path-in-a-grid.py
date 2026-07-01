from collections import deque

class Solution:
    def maximumSafenessFactor(self, grid):   #define a function according to question
        n = len(grid)
        INF = 10**9
        dist = [[INF] * n for _ in range(n)]
        q = deque()

        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    dist[i][j] = 0
                    q.append((i, j))

        directions = [(1,0), (-1,0), (0,1), (0,-1)]

        while q:
            x, y = q.popleft()

            for dx, dy in directions:
                nx, ny = x + dx, y + dy

                if 0 <= nx < n and 0 <= ny < n and dist[nx][ny] == INF:
                    dist[nx][ny] = dist[x][y] + 1
                    q.append((nx, ny))
        def canReach(limit):
            if dist[0][0] < limit:
                return False

            q = deque([(0, 0)])
            visited = [[False] * n for _ in range(n)]
            visited[0][0] = True

            while q:
                x, y = q.popleft()

                if (x, y) == (n - 1, n - 1):
                    return True

                for dx, dy in directions:
                    nx, ny = x + dx, y + dy

                    if (
                        0 <= nx < n and
                        0 <= ny < n and
                        not visited[nx][ny] and
                        dist[nx][ny] >= limit
                    ):
                        visited[nx][ny] = True
                        q.append((nx, ny))

            return False
        left = 0
        right = max(max(row) for row in dist)
        ans = 0

        while left <= right:
            mid = (left + right) // 2

            if canReach(mid):
                ans = mid
                left = mid + 1
            else:
                right = mid - 1

        return ans