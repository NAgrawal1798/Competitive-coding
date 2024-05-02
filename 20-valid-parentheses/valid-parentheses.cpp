class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if(st.empty()) {
                    return false;
                }
                if(s[i] == ')') {
                    char p = st.top();
                    cout<<p<<endl;
                    if(p != '(') {
                        return false;
                    }
                }
                if(s[i] == '}') {
                    char p = st.top();
                    if(p != '{') {
                        return false;
                    }
                }
                if(s[i] == ']') {
                    char p = st.top();
                    if(p != '[') {
                        return false;
                    }
                }
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};