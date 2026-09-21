class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> newDp(k, 0);

            int val = num % k;

            // Start a new subarray
            newDp[val]++;

            // Extend previous subarrays
            for (int rem = 0; rem < k; rem++) {
                int newRem = (rem * val) % k;

                newDp[newRem] += dp[rem];
            }

            // Add all subarrays ending here to answer
            for (int rem = 0; rem < k; rem++) {
                ans[rem] += newDp[rem];
            }

            dp = newDp;
        }

        return ans;
    }
};