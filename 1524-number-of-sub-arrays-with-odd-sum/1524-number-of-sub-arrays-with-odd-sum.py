class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        mod = 10**9 + 7
        odd = 0
        even = 1
        curr = 0
        ans = 0

        for x in arr:
            curr += x
            if curr % 2 == 0:
                ans += odd
                even += 1
            else:
                ans += even
                odd += 1

        return ans % mod
        