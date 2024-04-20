class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN+10000;
        int currMax = INT_MIN+10000;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            currMax = max(nums[i], currMax + nums[i]);
            ans = max(ans, currMax);
        }

        return ans;
    }
};
