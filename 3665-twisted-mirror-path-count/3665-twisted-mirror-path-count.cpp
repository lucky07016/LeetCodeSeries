
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        dp[1][0] = 1;
        dp[1][1] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0) {
                    dp[j + 1][0] =
                        (dp[j][0] + dp[j + 1][1]) % MOD;

                    dp[j + 1][1] = dp[j + 1][0];
                }
                else {
                    dp[j + 1][0] = dp[j + 1][1];
                    dp[j + 1][1] = dp[j][0];
                }
            }
        }

        return dp[n][0];
    }
};

