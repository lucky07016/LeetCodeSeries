class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        int ans = 0;

        int i = 0;

        while (i + k <= n) {

            // Try palindrome of length k
            if (isPalindrome(s, i, i + k - 1)) {
                ans++;
                i += k;
            }

            // Try palindrome of length k + 1
            else if (i + k < n &&
                     isPalindrome(s, i, i + k)) {
                ans++;
                i += k + 1;
            }

            else {
                i++;
            }
        }

        return ans;
    }
};