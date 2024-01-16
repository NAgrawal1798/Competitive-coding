class Solution {
public:
    // Use stack to get - O(n) soln
    int minInsertions(string s) {
        int minInsert = 0;
        stack<char>st;
        int n = s.length();
        for (int i=0; i<n; i++) {
            if (s[i] == '(') {
                st.push('(');
            } else { // Add condition to check the count
                if (s[i + 1] == ')') {
                    if (!st.empty()) {
                        st.pop();
                    } else {
                        minInsert++;
                    }
                    i++;
                } else {
                    if (!st.empty()) {
                        st.pop();
                        minInsert++;
                    } else {
                        minInsert += 2;
                    }
                }
            }
        }

        if(st.empty()) {
            return minInsert;
        }
        else {
            return minInsert + 2*st.size();
        }
    }
};