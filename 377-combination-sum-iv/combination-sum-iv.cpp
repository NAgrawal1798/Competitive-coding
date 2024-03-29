class Solution {
public:
    // without dp
    int helper(vector<int>& nums, int target, vector<int>& dp) {
        // base cases
        if(target < 0) {
            return 0;
        }
        if(target == 0) {
            return 1;
        }
        if(dp[target] != -1) {
            return dp[target];
        }
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            ans += helper(nums, target - nums[i], dp);
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        // use dp
        vector<int>dp(target+1, -1);
        return helper(nums, target, dp);
    }
};