class Solution {
public:
    bool isMatch(string s, string p) {
        int s_length = s.size();
        int p_length = p.size();

        vector<vector<bool>>dp(s_length + 1, vector<bool>(p_length + 1, false));

        dp[0][0] = true;

        for (int j = 2; j <= p.size(); ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i=1; i<=s_length; i++) {
            for (int j = 1; j<=p_length; j++) {
                if (s[i-1] == p[j-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2];

                    if (s[i-1] == p[j-2] || p[j-2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                }
            }
        }

        return dp[s_length][p_length];
    }
};