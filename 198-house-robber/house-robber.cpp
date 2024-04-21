class Solution {
public:
    int helper(vector<int>& nums, int i, bool flag, vector<int>&dp) {
        if(i >= nums.size()) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        int take = nums[i] + helper(nums, i+2, true, dp);
        int notTake = helper(nums, i+1, true, dp);
        return dp[i] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        bool flag = true;
        return helper(nums, 0, true, dp);
    }
};