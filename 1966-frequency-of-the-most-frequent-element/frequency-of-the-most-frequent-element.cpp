class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int ans = 0;
        long curr = 0;

        for(int right = 0; right < n; right++) {
            long target = nums[right];
            curr += target;

            while((right - left + 1) * target - curr > k) {
                curr -= nums[left];
                left++;
            }

            ans = max(right - left + 1, ans);
        }

        return ans;
    }
};