class Solution {
public:
    int helper(vector<int>& nums, int currentIndex, vector<int>& memo) {
        if (currentIndex >= nums.size()) {
            return 0;
        }

        // Check if the result is already computed
        if (memo[currentIndex] != -1) {
            return memo[currentIndex];
        }

        // Rob the current house
        int robCurrent = nums[currentIndex] + helper(nums, currentIndex + 2, memo);

        // Skip the current house and move to the next
        int skipCurrent = helper(nums, currentIndex + 1, memo);

        // Store the result in the memoization array
        memo[currentIndex] = max(robCurrent, skipCurrent);

        return memo[currentIndex];
    }

    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1); // Memoization array to store computed results
        return helper(nums, 0, memo);
    }
};
