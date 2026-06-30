class Solution:
    def subsets(self, nums):
        result = []
        subset = []

        def backtrack(start):
            result.append(subset[:])

            for i in range(start, len(nums)):
                subset.append(nums[i])
                backtrack(i + 1)
                subset.pop()

        backtrack(0)
        return result