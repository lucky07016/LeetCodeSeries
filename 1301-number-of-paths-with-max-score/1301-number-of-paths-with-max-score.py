from typing import List

class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        MOD = 10**9 + 7
        n = len(board)

        score = [[-1] * n for _ in range(n)]
        ways = [[0] * n for _ in range(n)]

        score[n - 1][n - 1] = 0
        ways[n - 1][n - 1] = 1

        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):

                if board[i][j] == 'X':
                    continue

                if i == n - 1 and j == n - 1:
                    continue

                best = -1
                count = 0

                for x, y in ((i + 1, j), (i, j + 1), (i + 1, j + 1)):
                    if x < n and y < n and score[x][y] != -1:

                        if score[x][y] > best:
                            best = score[x][y]
                            count = ways[x][y]

                        elif score[x][y] == best:
                            count = (count + ways[x][y]) % MOD

                if best == -1:
                    continue

                score[i][j] = best

                if board[i][j] not in ('S', 'E'):
                    score[i][j] += int(board[i][j])

                ways[i][j] = count % MOD

        if ways[0][0] == 0:
            return [0, 0]

        return [score[0][0], ways[0][0]]