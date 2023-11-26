class Solution {
public:
    // Dp solution
    // At most k transactions
    int helper(int canBuy, int i, int k, vector<int>& prices, vector<vector<vector<int>>>&dp) {
        if(k==0) {
            return 0;
        }
        if (i == prices.size()) {
            return 0;
        }
        if (dp[i][canBuy][k] != -1) {
            return dp[i][canBuy][k];
        }
        int profit = 0;
        if (canBuy) {
            int buy = -prices[i] + helper(false, i+1, k, prices, dp);
            int notBuy = 0 + helper(true, i+1, k, prices, dp);
            profit = max(buy, notBuy);

        } else {
            int sell = prices[i] + helper(true, i+1, k-1, prices, dp);
            int notSell = 0 + helper(false, i+1, k, prices, dp);
            profit = max(sell, notSell);
        }
        return dp[i][canBuy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        // 1st ->n
        // 2nd -> buy,canBuy
        // 3rd -> k
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return helper(true, 0, k, prices, dp);
    }
};