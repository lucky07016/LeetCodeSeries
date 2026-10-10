class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                                vector<int>& nums2,
                                int k1, int k2) {
        
        int n = nums1.size();
        vector<long long> diff(n);

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }

        sort(diff.rbegin(), diff.rend());

        long long k = (long long)k1 + k2;

        // Sentinel
        diff.push_back(0);

        for (int i = 0; i < n; i++) {

            long long count = i + 1;
            long long gap = diff[i] - diff[i + 1];
            long long operations = gap * count;

            // Completely reduce current level
            if (k >= operations) {
                k -= operations;
            }
            else {
                long long decrease = k / count;
                long long extra = k % count;

                long long level = diff[i] - decrease;

                long long ans = 0;

                // 'extra' elements get one additional reduction
                ans += extra * (level - 1) * (level - 1);

                ans += (count - extra) * level * level;

                // Remaining untouched elements
                for (int j = i + 1; j < n; j++) {
                    ans += diff[j] * diff[j];
                }

                return ans;
            }
        }

        return 0;
    }
};