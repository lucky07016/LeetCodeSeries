from collections import Counter

class Solution:
    def smallestPalindrome(self, s: str) -> str:
        freq = Counter(s)

        left = []
        middle = ""

        for c in map(chr, range(ord('a'), ord('z') + 1)):
            left.append(c * (freq[c] // 2))
            if freq[c] % 2:
                middle = c

        left = "".join(left)
        return left + middle + left[::-1]