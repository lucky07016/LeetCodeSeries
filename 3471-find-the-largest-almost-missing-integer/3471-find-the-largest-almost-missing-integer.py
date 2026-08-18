class Solution:
    def largestInteger(self, nums, k):
        n = len(nums)
        freq = {}

        for i in range(n - k + 1):
            seen = set()

            for j in range(i, i + k):
                seen.add(nums[j])

            for num in seen:
                freq[num] = freq.get(num, 0) + 1

        ans = -1

        for num in freq:
            if freq[num] == 1:
                ans = max(ans, num)

        return ans