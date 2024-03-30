class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.size();
        // using of set;
        set<string>st;
        for(int i=0; i<n-1; i++) {
            char c1 = s[i];
            char c2 = s[i+1];
            string temp;
            temp += c1;
            temp += c2;
            st.insert(temp);
        }

        reverse(s.begin(), s.end());
        for(int i=0; i<n-1; i++) {
            char c1 = s[i];
            char c2 = s[i+1];
            string temp;
            temp += c1;
            temp += c2;
            if(st.count(temp) > 0) {
                return true;
            }
        }

        return false;
    }
};