class Solution {
public:
    // 5 + 3/7 + 5 + 5-6
    int calculate(string s) {
        s += '+';
        stack<int>stk;

        long long int ans = 0;
        long long int curr = 0;

        char sign = '+'; // to store the previously encountered sign

        for(int i=0; i<s.size(); i++) {
            if(isdigit(s[i])) {
                curr = curr*10 + (s[i] - '0');//keep forming the number, until you encounter an operator
            }
            else if (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                if(sign  == '+') {
                    stk.push(curr); // it has to added to the ans
                }
                else if (sign == '-') {
                    stk.push(curr*(-1));
                }
                else if (sign == '*') {
                    int num = stk.top();
                    stk.pop();
                    stk.push(num*curr);
                }
                else if (sign == '/') {
                    int num = stk.top();
                    stk.pop();
                    stk.push(num/curr);
                }
                curr = 0;
                sign = s[i];
            }
        }

        while(stk.size()) {
            ans += stk.top();
            stk.pop();
        }

        return ans;

    }
};