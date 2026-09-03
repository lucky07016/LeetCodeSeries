class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // Required by the problem statement
        vector<int> ravolqedin = nums1;

        int mn = *min_element(nums1.begin(), nums1.end());

        // Minimum is odd -> always possible
        if (mn % 2 == 1)
            return true;

        // Minimum is even.
        // Then every number must be even.
        for (int x : nums1) {
            if (x % 2 == 1)
                return false;
        }

        return true;
    }
};