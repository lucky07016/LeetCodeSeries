from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:

        if not s or not t:
            return ""

        need = Counter(t)
        window = {}

        required = len(need)
        formed = 0

        left = 0

        ans = (float('inf'), 0, 0)

        for right in range(len(s)):

            ch = s[right]
            window[ch] = window.get(ch, 0) + 1

            if ch in need and window[ch] == need[ch]:
                formed += 1

            while left <= right and formed == required:

                if right - left + 1 < ans[0]:
                    ans = (right - left + 1, left, right)

                remove = s[left]
                window[remove] -= 1

                if remove in need and window[remove] < need[remove]:
                    formed -= 1

                left += 1

        if ans[0] == float('inf'):
            return ""

        return s[ans[1]:ans[2] + 1]      