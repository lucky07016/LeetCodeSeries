class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)

        # isPal[i][j] = True if s[i:j+1] is palindrome
        isPal = [[False] * n for _ in range(n)]

        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                if s[i] == s[j] and (j - i <= 2 or isPal[i + 1][j - 1]):
                    isPal[i][j] = True

        dp = [0] * n

        for i in range(n):
            if isPal[0][i]:
                dp[i] = 0
            else:
                dp[i] = float('inf')
                for j in range(i):
                    if isPal[j + 1][i]:
                        dp[i] = min(dp[i], dp[j] + 1)

        return dp[-1]