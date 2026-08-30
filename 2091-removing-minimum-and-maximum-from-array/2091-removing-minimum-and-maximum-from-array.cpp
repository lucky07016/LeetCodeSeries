class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0;
        int maxIdx = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;

            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);

        // 1. Delete both from front
        int option1 = right + 1;

        // 2. Delete both from back
        int option2 = n - left;

        // 3. Delete one from front and one from back
        int option3 = (left + 1) + (n - right);

        return min({option1, option2, option3});
    }
};