from collections import Counter

class Solution:
    def minimumPushes(self, word: str) -> int:
        freq = Counter(word)

        frequencies = sorted(freq.values(), reverse=True)

        pushes = 0

        for i, f in enumerate(frequencies):
            pushes += f * (i // 8 + 1)

        return pushes