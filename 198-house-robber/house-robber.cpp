class Solution {
public:
    int helper(vector<int>& nums, int currentIndex, vector<int>&memo) {
        if (currentIndex >= nums.size() ) {
            return 0;
        }

        if (memo[currentIndex] != -1) {
            return memo[currentIndex];
        }

        // pick or not pick algorithm
        int pick = nums[currentIndex] + helper(nums, currentIndex + 2, memo);
        int notPick = helper(nums, currentIndex + 1, memo);

        return memo[currentIndex] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        vector<int>memo(nums.size(), -1);
        return helper(nums, 0, memo);
    }
};