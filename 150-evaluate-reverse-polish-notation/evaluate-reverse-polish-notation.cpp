class Solution {
public:
    // use stack
    int performOperation(string x, string y, string sign) {
        int first = stoi(x);
        int second = stoi(y);
        if(sign == "+") {
            return first + second;
        }
        if (sign == "*") {
            return first * second;
        }
        if (sign == "/") {
            return first/second;
        }
        if (sign == "-") {
            return first-second;
        }
        return 0;
    }

    bool isSymbol(string token) {
        if (token == "+" || token == "-" || token == "/" || token == "*") {
            return true;
        }
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<string>s;
        int n = tokens.size();
        for(int i=0; i<n; i++) {
            if(isSymbol(tokens[i])) {
                string y = s.top();  // Pop the second operand first
                s.pop();
                string x = s.top();
                s.pop();
                int res = performOperation(x, y, tokens[i]);
                string result = to_string(res);
                s.push(result);
            } else {
                s.push(tokens[i]);
            }
        }
        string ans = s.top();
        int result = stoi(ans);
        return result;
    }
};