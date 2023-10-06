class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        vector<vector<int>>dp(size + 1, vector<int>(size + 1, 0));

        for (int iteration = 0; iteration < size; iteration++) {
            for (int j=0; j + iteration <size; j++) {
                if (iteration == 0) {
                    dp[j][j] = 1;
                }else if (iteration==1 && s[j] == s[j+1]) {
                   dp[j][j + 1] = 2;
               } else if (iteration==1 && s[j] != s[j+1]) {
                   dp[j][j + 1] = 1;
               }
                else if (iteration > 1) {
                    if( s[j] == s[j + iteration]) {
                   dp[j][j + iteration] = 2 + dp[j+1][j+iteration-1];
                    }else {
                        dp[j][j + iteration] = max(dp[j][j+iteration - 1], dp[j+1][j+iteration]);
               }
               }
               }
            }

                    return dp[0][size-1];

        }
};