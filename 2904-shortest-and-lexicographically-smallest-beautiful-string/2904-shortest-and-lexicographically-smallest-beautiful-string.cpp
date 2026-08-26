class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        int left = 0, count = 0;

        for (int right = 0; right < n; right++) {
            if (s[right] == '1') count++;

            while (count > k) {
                if (s[left] == '1') count--;
                left++;
            }

            if (count == k) {
                int l = left;
                while (s[l] == '0') l++; // drop leading zeros

                string cand = s.substr(l, right - l + 1);
                if (ans.empty() || cand.size() < ans.size() ||
                   (cand.size() == ans.size() && cand < ans)) {
                    ans = cand;
                }
            }
        }
        return ans;
    }
};