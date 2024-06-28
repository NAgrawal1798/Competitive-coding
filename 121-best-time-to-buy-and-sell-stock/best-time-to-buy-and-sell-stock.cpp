class Solution {
public:
    // as many as number of times
    int maxProfit(vector<int>& prices) {
       int buy = prices[0];
       int profit = 0;

       int n = prices.size();
       for(int i=1; i<n; i++) {
            profit = max(profit, prices[i] - buy);
            buy = min(prices[i], buy);
       }

       return profit;
    }
};