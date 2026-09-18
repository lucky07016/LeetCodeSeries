class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // First and last occurrence
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Only first occurrences can start a minimal valid interval
        for (int c = 0; c < 26; c++) {
            if (first[c] == n)
                continue;

            int L = first[c];
            int R = last[c];
            bool valid = true;

            // Expand interval
            for (int i = L; i <= R; i++) {
                int ch = s[i] - 'a';

                // This character starts before our interval
                if (first[ch] < L) {
                    valid = false;
                    break;
                }

                R = max(R, last[ch]);
            }

            if (valid) {
                intervals.push_back({L, R});
            }
        }

        // Greedy: choose interval with earliest ending position
        sort(intervals.begin(), intervals.end(),
             [](auto& a, auto& b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prevEnd = -1;

        for (auto [L, R] : intervals) {
            if (L > prevEnd) {
                ans.push_back(s.substr(L, R - L + 1));
                prevEnd = R;
            }
        }

        return ans;
    }
};