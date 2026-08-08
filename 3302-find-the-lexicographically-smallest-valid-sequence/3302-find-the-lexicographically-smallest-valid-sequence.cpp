class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = maximum number of characters of word2
        // that can be matched as a subsequence in word1[i...]
        vector<int> suf(n + 1, 0);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];

            if (j >= 0 && word1[i] == word2[j]) {
                suf[i]++;
                j--;
            }
        }

        vector<int> ans;

        j = 0;
        bool changed = false;

        for (int i = 0; i < n && j < m; i++) {

            // Characters match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Use the one allowed mismatch
            else if (!changed) {
                int remaining = m - j - 1;

                // Check whether the remaining characters
                // can be matched after index i.
                if (suf[i + 1] >= remaining) {
                    ans.push_back(i);
                    j++;
                    changed = true;
                }
            }
        }

        if (ans.size() == m)
            return ans;

        return {};
    }
};