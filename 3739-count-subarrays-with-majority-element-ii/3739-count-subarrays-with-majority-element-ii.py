class Fenwick:
    def __init__(self, n):
        self.bit = [0] * (n + 1)

    def update(self, i, delta):
        while i < len(self.bit):
            self.bit[i] += delta
            i += i & -i

    def query(self, i):
        s = 0
        while i > 0:
            s += self.bit[i]
            i -= i & -i
        return s


class Solution:
    def countMajoritySubarrays(self, nums, target):
        prefix = [0]

        for x in nums:
            if x == target:
                prefix.append(prefix[-1] + 1)
            else:
                prefix.append(prefix[-1] - 1)

        values = sorted(set(prefix))
        rank = {v: i + 1 for i, v in enumerate(values)}

        bit = Fenwick(len(values))

        ans = 0

        for p in prefix:
            ans += bit.query(rank[p] - 1)
            bit.update(rank[p], 1)

        return ans