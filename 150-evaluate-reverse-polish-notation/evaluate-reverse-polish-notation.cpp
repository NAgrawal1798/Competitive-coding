class Solution {
public:
    int eval(int a, int b, char sign) {
        switch (sign) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a/b;
            default:
                return 0;
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int n = tokens.size();
        for(int i=0; i<n; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                if (tokens[i] == "+") {
                    int res = eval(a, b, '+');
                    s.push(res);
                }
                if (tokens[i] == "-") {
                    int res = eval(a, b, '-');
                    s.push(res);
                }
                if (tokens[i] == "*") {
                    int res = eval(a, b, '*');
                    s.push(res);
                }
                if (tokens[i] == "/") {
                    int res = eval(a, b, '/');
                    s.push(res);
                }
            } else {
                s.push(stoi(tokens[i]));
            }
        }

        int result = s.top();
        return result;

    }
};