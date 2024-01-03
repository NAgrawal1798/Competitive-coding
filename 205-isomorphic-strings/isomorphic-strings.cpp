class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        if (n != m) {
            return false;
        }

        map<char, char>mp;
        set<char>st;

        for (int i=0; i<s.length(); i++) {
            if (mp.find(s[i]) != mp.end()) {
                if (mp[s[i]] != t[i]) {
                    return false;
                }
            } else {
                if (st.count(t[i]) > 0) {
                    return false;
                }
            }
            st.insert(t[i]);
            mp[s[i]] = t[i];
        }
        return true;

        
    }
};