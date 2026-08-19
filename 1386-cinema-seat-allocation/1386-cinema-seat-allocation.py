from collections import defaultdict
from typing import List

class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        reserved = defaultdict(set)

        for row, seat in reservedSeats:
            reserved[row].add(seat)

        ans = (n - len(reserved)) * 2

        for seats in reserved.values():
            left = all(x not in seats for x in [2, 3, 4, 5])
            middle = all(x not in seats for x in [4, 5, 6, 7])
            right = all(x not in seats for x in [6, 7, 8, 9])

            if left and right:
                ans += 2
            elif left or middle or right:
                ans += 1

        return ans