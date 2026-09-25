
class Solution {
public:

    // Combine every string from a with every string from b
    set<string> multiply(set<string>& a, set<string>& b) {
        set<string> result;

        for (string x : a) {
            for (string y : b) {
                result.insert(x + y);
            }
        }

        return result;
    }

    set<string> solve(string& s, int& i) {
        set<string> result;
        set<string> curr = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                // Union operation
                result.insert(curr.begin(), curr.end());

                curr = {""};
                i++;
            }

            else if (s[i] == '{') {
                // Recursively solve nested braces
                i++;

                set<string> temp = solve(s, i);

                i++; // Skip closing brace

                curr = multiply(curr, temp);
            }

            else {
                // Normal character
                set<string> temp = {string(1, s[i])};

                curr = multiply(curr, temp);

                i++;
            }
        }

        result.insert(curr.begin(), curr.end());

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};