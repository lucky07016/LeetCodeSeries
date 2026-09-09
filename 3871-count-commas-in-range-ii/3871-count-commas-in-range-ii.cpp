class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        // Required by the problem statement
        long long nalverqito = n;

        for (long long x = 1000; x <= n; x *= 1000) {
            ans += n - x + 1;
        }

        return ans;
    }
};