class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;

        int n = s.length();
        set<char>st;
        int maxi = 0;

        while(j<n) {
            if (st.count(s[j]) > 0) {
                maxi = max(j-i, maxi);
                while(i<n && st.count(s[j]) > 0) {
                    st.erase(s[i]);
                    i++;
                }
                st.insert(s[j]);
            } else {
                st.insert(s[j]);
            }
            j++;
        }
        maxi = max(maxi, j-i);
        return maxi;
    }
};