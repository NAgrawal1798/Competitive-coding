class Solution {
public:
    int f(int n ,int e , vector<vector<int>>&dp) {
        if (n==0 || n==1) {
            return n;
        }
        if (e==1) {
            return n;
        }
        if (dp[n][e] != -1) {
            return dp[n][e];
        }
        int ans = INT_MAX;
        for (int i=1; i<=n; i++) {
            int willBreak = f(i-1, e-1, dp);
            int notBreak = f(n-i, e, dp);
            ans = min(ans, max(willBreak, notBreak) + 1);
        }
        return dp[n][e] = ans;

    }
    int twoEggDrop(int n) {
        vector<vector<int>>dp(10001, vector<int>(3,-1));
        return f(n,2, dp);
    }
};