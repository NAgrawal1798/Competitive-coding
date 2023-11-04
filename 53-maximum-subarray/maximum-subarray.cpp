class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;

        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (nums[i] < 0) {
                sum += nums[i];
                ans = max(sum, ans);
                if (sum < 0) {
                    ans = max(sum, ans);
                    sum =0;
                }
            } else {
                sum += nums[i];
                ans = max(sum, ans);
            }
        }
        return ans;
    }
};