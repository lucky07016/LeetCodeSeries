
class Solution {
    multiset<long long> lo, hi;
    long long sumLo = 0, sumHi = 0;

    void balance() {
        while (lo.size() > hi.size() + 1) {
            long long v = *lo.rbegin();
            lo.erase(prev(lo.end()));
            sumLo -= v;

            hi.insert(v);
            sumHi += v;
        }

        while (lo.size() < hi.size()) {
            long long v = *hi.begin();
            hi.erase(hi.begin());
            sumHi -= v;

            lo.insert(v);
            sumLo += v;
        }
    }

    void add(long long v) {
        if (lo.empty() || v <= *lo.rbegin()) {
            lo.insert(v);
            sumLo += v;
        } else {
            hi.insert(v);
            sumHi += v;
        }
        balance();
    }

    void remove(long long v) {
        auto it = lo.find(v);

        if (it != lo.end()) {
            lo.erase(it);
            sumLo -= v;
        } else {
            it = hi.find(v);
            hi.erase(it);
            sumHi -= v;
        }

        balance();
    }

    long long getCost() {
        long long median = *lo.rbegin();

        return median * lo.size() - sumLo
             + sumHi - median * hi.size();
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        lo.clear();
        hi.clear();
        sumLo = sumHi = 0;

        // Calculate cost of every window of size x
        vector<long long> cost(n - x + 1);

        for (int i = 0; i < x; i++)
            add(nums[i]);

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            cost[i - x + 1] = getCost();
        }

        // DP: minimum cost to select t windows
        const long long INF = 1e18;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int t = 1; t <= k; t++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                // Skip current position
                curr[i] = curr[i - 1];

                // Select a window ending at i - 1
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
