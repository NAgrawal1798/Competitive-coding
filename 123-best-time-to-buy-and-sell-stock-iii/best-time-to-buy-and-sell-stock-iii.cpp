class Solution {
public:
    // dp question
    int helper(vector<int>& prices, int index, int k, int flag, vector<vector<vector<int>>>& dp) {
        // base case
        if (k==0 || index == prices.size()) {
            return 0;
        }

        if (dp[index][k][flag]  != -1) {
            return dp[index][k][flag];
        }

        // take or not take
        int take =0 ;
        int notTake = 0;
        if (flag) {
            // 2 choices
            int buy = -prices[index] + helper(prices, index + 1, k, !flag, dp);
            int notBuy = 0 + helper(prices, index + 1, k, flag, dp);
            take = max(buy, notBuy);
        } else {
            int sell = prices[index] + helper(prices, index +1, k - 1, !flag, dp);
            int notSell = 0 + helper(prices, index +1 , k, flag, dp);
            notTake = max(sell, notSell);
        }

        return dp[index][k][flag] = max(take,notTake);
    }
    int maxProfit(vector<int>& prices) {
        int k=2;
        // 3d dp
        vector<vector<vector<int>>>dp(prices.size(), vector<vector<int>>(k+1, vector<int>(2, -1)));
        return helper(prices, 0, k, 1, dp);
    }
};