class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_set<int> uniqueElements;
        long long sum = 0, maxSum = 0;

        int left = 0, right = 0;

        while (right < n) {
            while (uniqueElements.find(nums[right]) != uniqueElements.end()) {
                uniqueElements.erase(nums[left]);
                sum -= nums[left];
                left++;
            }

            uniqueElements.insert(nums[right]);
            sum += nums[right];
            right++;

            if (right - left == k) {
                maxSum = max(maxSum, sum);
                uniqueElements.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
        }

        return maxSum;
    }
};
