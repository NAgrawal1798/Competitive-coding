class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int n = s.size();

        int i=0;
        int j=0;
        set<char>st;
        while(j<n) {
            // Remove element from set
            if (st.count(s[j]) > 0) {
                while(!st.empty() && st.count(s[j]) > 0) {
                    st.erase(s[i]);
                    i++;
                }
            }
            st.insert(s[j]);
            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};