class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<long long> squares;

        for (int x : nums) {
            squares.push_back(1LL * x * x);
        }

        sort(squares.begin(), squares.end());

        int m = n / 2;

        long long ans = 0;

        // Smallest values get negative sign
        for (int i = 0; i < m; i++) {
            ans -= squares[i];
        }

        // Largest values get positive sign
        for (int i = m; i < n; i++) {
            ans += squares[i];
        }

        return ans;
    }
};