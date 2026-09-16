class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<vector<long long>> closed(
            n, vector<long long>(k + 1, 0)
        );

        vector<vector<long long>> open(
            n, vector<long long>(k + 1, 0)
        );

        // At point 0:
        // either do nothing, or start a segment
        closed[0][0] = 1;
        open[0][0] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {

                // Don't use point i to close anything
                closed[i][j] = closed[i - 1][j];

                // Continue an already open segment
                // OR start a new segment at point i
                open[i][j] =
                    (open[i - 1][j] + closed[i - 1][j]) % MOD;

                if (j > 0) {
                    // Close an open segment at point i
                    closed[i][j] =
                        (closed[i][j] + open[i - 1][j - 1]) % MOD;

                    // Close a segment at i and immediately
                    // start another segment at i.
                    // This allows segments to share endpoints.
                    open[i][j] =
                        (open[i][j] + open[i - 1][j - 1]) % MOD;
                }
            }
        }

        return closed[n - 1][k];
    }
};