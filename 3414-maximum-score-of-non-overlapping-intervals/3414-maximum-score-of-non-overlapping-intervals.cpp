class Solution {
public:
    struct State {
        long long weight = 0;
        vector<int> indices;
    };

    vector<vector<int>> arr;
    vector<vector<State>> dp;
    vector<vector<bool>> vis;
    vector<int> starts;
    int n;

    State better(State a, State b) {
        if (a.weight != b.weight)
            return a.weight > b.weight ? a : b;

        return a.indices < b.indices ? a : b;
    }

    State solve(int i, int k) {
        if (i >= n || k == 0)
            return {0, {}};

        if (vis[i][k])
            return dp[i][k];

        vis[i][k] = true;

        // Option 1: skip current interval
        State skip = solve(i + 1, k);

        // Find next interval with start > current end
        int nextIndex = upper_bound(
            starts.begin(),
            starts.end(),
            arr[i][1]
        ) - starts.begin();

        // Option 2: take current interval
        State next = solve(nextIndex, k - 1);

        State take;
        take.weight = arr[i][2] + next.weight;
        take.indices = next.indices;
        take.indices.push_back(arr[i][3]);

        sort(take.indices.begin(), take.indices.end());

        dp[i][k] = better(take, skip);

        return dp[i][k];
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        // Store original index
        for (int i = 0; i < n; i++) {
            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by start
        sort(arr.begin(), arr.end());

        for (auto &x : arr)
            starts.push_back(x[0]);

        dp.resize(n, vector<State>(5));
        vis.resize(n, vector<bool>(5, false));

        return solve(0, 4).indices;
    }
};