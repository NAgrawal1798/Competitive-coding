class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(100,0);

        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 2;

        for (int i = 4; i<=n; i++) {
            int num = i;
            for (int j=1; j<=num; j++) {
                int x = j;
                int y = num - j;
                dp[num] =  max({dp[num], x*y, dp[x] * y, x * dp[y]});
            }
        }

        return dp[n];
    }
};