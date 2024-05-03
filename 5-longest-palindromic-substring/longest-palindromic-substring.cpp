class Solution {
public:
    void solve(vector<vector<bool>>&dp, int i, int j, string &s) {
        if(i==j) {
            dp[i][j] = true;
        } else if(j-i == 1) {
            if(s[i] == s[j]) {
                dp[i][j] = true;
            }
        } else {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1];
            }
        }
    }
    std::string longestPalindrome(std::string s) {
       int n = s.size();
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        int maxi = 0;
        int ans_i =0;
        for(int g=0; g<n; g++) {
            for(int i=0, j=g; j<n; i++,j++) {
                solve(dp, i, j, s);
                if (dp[i][j]) {
                    if (maxi < (j-i+1)) {
                        maxi = j-i+1;
                        ans_i = i;
                    }
                }
            }
        }

        return s.substr(ans_i, maxi);
    }
};