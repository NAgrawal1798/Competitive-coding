class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
       // sum kind of math rule and use sorting
       sort(coins.begin(), coins.end());
       long sum = 0;
       int ans = 0;

       for(auto coin: coins) {
            while(coin > sum + 1) {
                ans++;
                sum += sum + 1;
            }
            sum += coin;
       }

       while(sum < target) {
        sum += sum + 1;
        ans++;
       }

       return ans;

    }
};