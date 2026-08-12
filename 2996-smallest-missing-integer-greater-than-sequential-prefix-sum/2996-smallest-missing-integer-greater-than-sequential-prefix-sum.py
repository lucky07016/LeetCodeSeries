class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        total = nums[0]

        # Find sequential prefix
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1] + 1:
                total += nums[i]
            else:
                break

        # Store all numbers for O(1) lookup
        seen = set(nums)

        # Find smallest missing integer >= total
        while total in seen:
            total += 1

        return total