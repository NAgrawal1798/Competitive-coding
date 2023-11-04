class Solution {
public:

    // Function to check if a string of parentheses is balanced or not
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
        if (current.length() == n*2) {
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
        // store result
        vector<string>combinations;
        generateParenthesisHelper(n, combinations, "", 0, 0);
        return combinations;
    }
};