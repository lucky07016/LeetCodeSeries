class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;

        vector<int> bitCount(32, 0);

        // Count frequency of each bit
        for (int num : nums) {
            for (int bit = 0; bit < 32; bit++) {
                if (num & (1 << bit)) {
                    bitCount[bit]++;
                }
            }
        }

        long long ans = 0;

        // Build k maximum possible numbers
        for (int i = 0; i < k; i++) {
            long long x = 0;

            for (int bit = 0; bit < 32; bit++) {
                if (bitCount[bit] > 0) {
                    x |= (1LL << bit);
                    bitCount[bit]--;
                }
            }

            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};