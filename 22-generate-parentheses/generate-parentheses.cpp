class Solution {
public:
    // Function to check if a string of parentheses is balanced
    bool isBalanced(string s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') {
                balance++;
            } else if (c == ')') {
                balance--;
                if (balance < 0) {
                    return false;
                }
            }
        }
        return balance == 0;
    }

    void generateParenthesisHelper(int n, vector<string>& combinations, string current, int open, int close) {
        if (current.length() == 2 * n) {
            if (isBalanced(current)) {
                combinations.push_back(current);
            }
            return;
        }

        if (open < n) {
            generateParenthesisHelper(n, combinations, current + "(", open + 1, close);
        }
        if (close < open) {
            generateParenthesisHelper(n, combinations, current + ")", open, close + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> combinations;
        generateParenthesisHelper(n, combinations, "", 0, 0);
        return combinations;
    }
};
