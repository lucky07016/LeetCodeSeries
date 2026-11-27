class Solution:
    def maximumSaleItems(self, items: List[List[int]], budget: int) -> int:
        mn = min(price for _, price in items)
        dp = [0] * (budget + 1)

        for factor, price in items:
            gain = sum(1 for f, _ in items if f % factor == 0)
            for c in range(budget, price - 1, -1):
                dp[c] = max(dp[c], dp[c - price] + gain)

        ans = 0
        for spent in range(budget + 1):
            ans = max(ans, dp[spent] + (budget - spent) // mn)
        return ans