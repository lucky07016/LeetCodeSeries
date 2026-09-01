class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> pairXor(MAXX, false);
        vector<bool> tripletXor(MAXX, false);

        // Step 1: all possible XORs of two numbers
        for (int a : nums) {
            for (int b : nums) {
                pairXor[a ^ b] = true;
            }
        }

        // Step 2: combine pair XOR with third number
        for (int x = 0; x < MAXX; x++) {
            if (!pairXor[x])
                continue;

            for (int num : nums) {
                tripletXor[x ^ num] = true;
            }
        }

        int ans = 0;

        for (bool possible : tripletXor) {
            if (possible)
                ans++;
        }

        return ans;
    }
};