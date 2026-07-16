from math import gcd

class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        prefix_gcd = []
        mx = 0
        for x in nums:
            mx = max(mx, x)
            prefix_gcd.append(gcd(x, mx))
        prefix_gcd.sort()
        ans = 0
        n = len(prefix_gcd)
        for i in range(n // 2):
            ans += gcd(prefix_gcd[i], prefix_gcd[n - 1 - i])

        return ans