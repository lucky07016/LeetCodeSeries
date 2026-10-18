class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<vector<long long>> C;

    long long solve(vector<int>& nums) {
        if (nums.size() <= 2)
            return 1;

        vector<int> left, right;

        int root = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long leftWays = solve(left);
        long long rightWays = solve(right);

        int l = left.size();
        int r = right.size();

        // Choose positions of left subtree elements
        long long ways = C[l + r][l];

        ways = ways * leftWays % MOD;
        ways = ways * rightWays % MOD;

        return ways;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // Build combination table
        C.assign(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            C[i][0] = C[i][i] = 1;

            for (int j = 1; j < i; j++) {
                C[i][j] =
                    (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};