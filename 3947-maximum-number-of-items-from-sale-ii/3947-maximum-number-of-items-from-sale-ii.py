class Solution:
    def maximumSaleItems(self, items: List[List[int]], budget: int) -> int:
        n = len(items)
        cnt = [0] * (n + 1)
        for f, _ in items:
            cnt[f] += 1

        mult = [0] * (n + 1)
        for f in range(1, n + 1):
            mult[f] = sum(cnt[f::f])

        mn = min(p for _, p in items)
        deals = sorted((p, mult[f] - 1) for f, p in items)

        ans = 0
        for price, cap in deals:
            if price > 2 * mn:
                break
            if cap <= 0:
                continue
            k = min(cap, budget // price)
            budget -= k * price
            ans += 2 * k

        ans += budget // mn
        return ans