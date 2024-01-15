class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        // dp[i][j] represents the maximum difference between the scores of the two players
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Initialize the base case: single piles have the same value
        for (int i = 0; i < n; ++i) {
            dp[i][i] = piles[i];
        }

        // Build the DP table
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }

        // The final result is in the top-right cell of the DP table
        return dp[0][n - 1] > 0;
    }
};
