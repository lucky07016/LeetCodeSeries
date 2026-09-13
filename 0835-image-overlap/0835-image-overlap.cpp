class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> a, b;
        int n = img1.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1)
                    a.push_back({i, j});

                if (img2[i][j] == 1)
                    b.push_back({i, j});
            }
        }

        map<pair<int,int>, int> freq;
        int ans = 0;

        for (auto [r1, c1] : a) {
            for (auto [r2, c2] : b) {
                int dr = r2 - r1;
                int dc = c2 - c1;

                freq[{dr, dc}]++;
                ans = max(ans, freq[{dr, dc}]);
            }
        }

        return ans;
    }
};