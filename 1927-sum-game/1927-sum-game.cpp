class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftSum = 0, rightSum = 0;
        int leftQuestions = 0, rightQuestions = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                leftQuestions++;
            else
                leftSum += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rightQuestions++;
            else
                rightSum += num[i] - '0';
        }

        int totalQuestions = leftQuestions + rightQuestions;

        // Alice makes the final move.
        if (totalQuestions % 2 == 1)
            return true;

        // Bob wins only if the two sides can be perfectly balanced.
        return 2 * (leftSum - rightSum) !=
               9 * (rightQuestions - leftQuestions);
    }
};