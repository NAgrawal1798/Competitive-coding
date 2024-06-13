class Solution {
public:
    int calculate(string s) {
        stack<int>st;

        s += '+';
        char sign = '+';

        long long int ans = 0;
        long long int curr = 0;

        for(int i=0; i<s.size(); i++) {
            if(isdigit(s[i])) {
                curr = curr* 10 + (s[i] - '0');
            } else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                if (sign == '+') {
                    st.push(curr);
                } else if (sign == '-') {
                    st.push((-1) * curr);
                } else if (sign == '*') {
                    int num = st.top();
                    st.pop();
                    st.push(num*curr);
                } else if (sign == '/') {
                    int num = st.top();
                    st.pop();
                    st.push(num/curr);
                }
                sign = s[i];
                curr = 0;
            }
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }

};