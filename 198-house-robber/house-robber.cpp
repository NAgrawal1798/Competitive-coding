class Solution {
public:
    // recursion is correct but dp is not correct
    int dp[105][2];//[2] >> take or not take
    int helper(vector<int>& nums, int i, bool flag) {
        if(i >= nums.size()) {
            return 0;
        }
        if(dp[i][flag] != -1) {
            return dp[i][flag];
        }
        int take = 0;
        int notTake = 0;
        int sum = 0;
        if(flag) {
            int taken = nums[i] + helper(nums, i+1, false);
            int notTaken = helper(nums, i+1, true);
            sum = max(taken, notTaken);
        } else {
            notTake = helper(nums, i+1, true);
        }
        sum = max(sum, notTake);
        return dp[i][flag] = sum;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        bool flag = true;
        return helper(nums, 0, true);
    }
};