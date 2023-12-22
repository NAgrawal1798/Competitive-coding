class Solution {
public:
    // sliding window problem
    int longestContinuousSubstring(string s) {
        int n = s.length();

        if (n==1) {
            return 1;
        }

        int i=0;
        int j=1;
        int ans = 1;

        while(j<n) {
            if (s[j] == s[j-1] + 1) {
                j++;
                ans = max(j-i, ans);
            } else {
                i=j;
                j++;
            }
        }

        return ans;
    }
};