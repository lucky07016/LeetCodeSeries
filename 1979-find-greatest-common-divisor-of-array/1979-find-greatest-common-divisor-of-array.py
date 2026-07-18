class Solution:
    def findGCD(self, nums):
        minimum = min(nums)
        maximum = max(nums)

        while maximum != 0:
            minimum, maximum = maximum, minimum % maximum

        return minimum      