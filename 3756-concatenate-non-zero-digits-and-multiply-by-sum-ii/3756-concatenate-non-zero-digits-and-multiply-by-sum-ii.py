from typing import List
from bisect import bisect_left, bisect_right

class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7

        pos = []
        digits = []

        for i, ch in enumerate(s):
            if ch != '0':
                pos.append(i)
                digits.append(int(ch))

        m = len(digits)

        prefSum = [0] * (m + 1)
        for i in range(m):
            prefSum[i + 1] = prefSum[i] + digits[i]

        pow10 = [1] * (m + 1)
        for i in range(1, m + 1):
            pow10[i] = (pow10[i - 1] * 10) % MOD

        prefNum = [0] * (m + 1)
        for i in range(m):
            prefNum[i + 1] = (prefNum[i] * 10 + digits[i]) % MOD

        ans = []

        for l, r in queries:
            L = bisect_left(pos, l)
            R = bisect_right(pos, r)

            if L == R:
                ans.append(0)
                continue

            length = R - L

            num = (prefNum[R] - prefNum[L] * pow10[length]) % MOD
            digit_sum = prefSum[R] - prefSum[L]

            ans.append((num * digit_sum) % MOD)

        return ans