class Solution {
public:
    int getEvenOdd(int num) {
        return num % 2 == 0;
    }
    long long dfs(int ind, int prevPar, vector<int>& nums, int n, int penalty, vector<vector<long long>>& dp) {
        if (ind == n) return 0;
        if (dp[ind][prevPar] != -1) return dp[ind][prevPar];

        long long pick = 0, notPick = 0;
        int currPar = getEvenOdd(nums[ind]);

        notPick = dfs(ind + 1, prevPar, nums, n, penalty, dp);
        pick = nums[ind] + dfs(ind + 1, currPar, nums, n, penalty, dp);
        if (prevPar != currPar) pick -= penalty;
        
        return dp[ind][prevPar] = max(notPick, pick);
    }
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2, -1));
        return dfs(0, getEvenOdd(nums[0]), nums, n, x, dp);
    }
};