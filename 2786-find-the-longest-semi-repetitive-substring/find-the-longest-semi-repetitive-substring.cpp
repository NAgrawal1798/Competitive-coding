class Solution {
public:
    // sliding window problem
    int longestSemiRepetitiveSubstring(string s) {
        int i=0;
        int j=1;
                int n=s.size();

        if(n==1) {
            return 1;
        }

        int ans=0;
        int cnt=0;
        while(j<n) {
            if(s[j] == s[j-1]) {
                cnt++;
            }

            if(cnt>1) {
                ans = max(ans, j-i);
                i++;
                while(s[i] != s[i-1] && i<n) {
                    i++;
                } 
                cnt--;
            }
            j++;

        }

        ans = max(ans, j-i);

        return ans;
    }
};