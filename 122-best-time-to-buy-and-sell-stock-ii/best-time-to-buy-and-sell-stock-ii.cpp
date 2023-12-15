class Solution {
public:
    // Dp solution
    // At most k transactions
    int helper(int canBuy, int i, vector<int>& prices, vector<vector<int>>&dp) {
        if (i == prices.size()) {
            return 0;
        }
        if (dp[i][canBuy] != -1) {
            return dp[i][canBuy];
        }
        int profit = 0;
        if (canBuy) {
            int buy = -prices[i] + helper(false, i+1, prices, dp);
            int notBuy = 0 + helper(true, i+1, prices, dp);
            profit = max(buy, notBuy);

        } else {
            int sell = prices[i] + helper(true, i+1, prices, dp);
            int notSell = 0 + helper(false, i+1, prices, dp);
            profit = max(sell, notSell);
        }
        return dp[i][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // 1st ->n
        // 2nd -> buy,canBuy
        // 3rd -> k
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        
        return helper(true, 0, prices, dp);
    }
};