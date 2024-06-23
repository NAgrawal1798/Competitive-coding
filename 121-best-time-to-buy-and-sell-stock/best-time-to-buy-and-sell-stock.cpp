class Solution {
public:
    // as many as number of times
    int maxProfit(vector<int>& prices) {
        int ans =0;
        int n = prices.size();
        vector<int>pre(n);
        vector<int>suf(n);

        pre[0] = prices[0];
        suf[n-1] = prices[n-1];
        for(int i=1; i<n; i++){
            pre[i] = min(prices[i], pre[i-1]);
        }

        for(int i=n-2; i>=0; i--){
            suf[i] = max(prices[i], suf[i+1]);
        }

        for(int i=0; i<n; i++) {
            ans = max(ans, suf[i] - pre[i]);
        }

        return ans;
    }
};