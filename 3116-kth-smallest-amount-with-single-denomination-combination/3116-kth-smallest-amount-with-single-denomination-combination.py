from math import gcd


class Solution:
    def findKthSmallest(self, coins, k):
        # Remove redundant coins
        coins.sort()

        filtered = []

        for coin in coins:
            if not any(coin % x == 0 for x in filtered):
                filtered.append(coin)

        coins = filtered
        n = len(coins)

        def count(x):
            """
            Count numbers <= x that are divisible
            by at least one coin.
            """
            total = 0

            # Iterate through all non-empty subsets
            for mask in range(1, 1 << n):
                lcm = 1
                bits = 0

                for i in range(n):
                    if mask & (1 << i):
                        bits += 1

                        g = gcd(lcm, coins[i])
                        lcm = lcm // g * coins[i]

                        # LCM is already larger than x.
                        # This subset contributes nothing.
                        if lcm > x:
                            break

                else:
                    contribution = x // lcm

                    # Odd number of elements -> add
                    # Even number of elements -> subtract
                    if bits % 2 == 1:
                        total += contribution
                    else:
                        total -= contribution

            return total

        # Binary search
        left = 1
        right = min(coins) * k

        while left < right:
            mid = (left + right) // 2

            if count(mid) >= k:
                right = mid
            else:
                left = mid + 1

        return left