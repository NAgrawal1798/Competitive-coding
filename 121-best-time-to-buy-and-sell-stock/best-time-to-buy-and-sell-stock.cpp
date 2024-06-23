class Solution {
public:
    // as many as number of times
    int maxProfit(vector<int>& prices) {
       int buy = prices[0];
       int ans = 0;
       for(int i=1; i<prices.size(); i++) {
            ans = max(ans, prices[i] - buy);
            buy = min(prices[i], buy);
       }

       return ans;
    }
};