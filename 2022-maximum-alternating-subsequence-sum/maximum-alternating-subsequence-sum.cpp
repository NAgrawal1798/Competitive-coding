class Solution {
public:
    // naive approach
    // 1. Find all the subsequences and find alteranting sum
    // To find all the alternating subsequence apply backtracking
    long long dp[100006][2];
    long long solve(int i, int x, vector<int>& nums) {
        // base case
        if(i == nums.size()) {
            return 0;
        }

        // dp found case
        if(dp[i][x] != -1) {
            return dp[i][x];
        }

        long long skip = solve(i+1, x, nums);
        long long consider;
        if(x==0) {
            consider = nums[i] + solve(i+1, 1, nums);
        } else {
            consider = -nums[i] + solve(i+1, 0, nums);
        }
        return dp[i][x] = max(skip, consider);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,-1, sizeof(dp));
        return solve(0,0,nums);
    }
};