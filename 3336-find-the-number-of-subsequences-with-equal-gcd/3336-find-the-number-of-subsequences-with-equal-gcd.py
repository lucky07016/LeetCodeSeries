from math import gcd
from functools import lru_cache

class Solution:
    def subsequencePairCount(self, nums):
        MOD = 10**9 + 7
        n = len(nums)

        @lru_cache(None)
        def dfs(i, g1, g2):
            if i == n:
                return 1 if g1 == g2 and g1 != 0 else 0
            ans = dfs(i + 1, g1, g2)
            ans += dfs(i + 1, gcd(g1, nums[i]), g2)
            ans += dfs(i + 1, g1, gcd(g2, nums[i]))

            return ans % MOD

        return dfs(0, 0, 0)