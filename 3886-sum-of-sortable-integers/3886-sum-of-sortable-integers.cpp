
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        // Prefix maximum
        vector<int> prefMax(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        // Suffix minimum
        vector<int> suffMin(n + 1, INT_MAX);
        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        // Count adjacent descents
        vector<int> prefDrop(n, 0);
        for (int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1]
                         + (nums[i - 1] > nums[i]);
        }

        // Check whether block size k is sortable
        auto check = [&](int k) -> bool {
            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;

                int drops = prefDrop[end] - prefDrop[start];

                // Circular boundary: last element -> first
                if (nums[end] > nums[start]) {
                    drops++;
                }

                // Block must be rotatable into sorted order,
                // and all earlier elements must precede it.
                if (drops > 1 ||
                    prefMax[start] > suffMin[start]) {
                    return false;
                }
            }

            return true;
        };

        int ans = 0;

        // Enumerate divisors in O(sqrt(n))
        for (int d = 1; d <= n / d; d++) {
            if (n % d == 0) {
                if (check(d)) {
                    ans += d;
                }

                int other = n / d;

                if (other != d && check(other)) {
                    ans += other;
                }
            }
        }

        return ans;
    }
};
