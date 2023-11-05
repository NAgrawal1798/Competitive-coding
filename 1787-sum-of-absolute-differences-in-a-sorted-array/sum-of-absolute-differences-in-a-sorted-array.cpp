class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
       vector<int>res(nums.size());

       int sum=0;
       int n = nums.size();
       int prefix_sum = 0;

       for (int i=0; i<n; i++) {
           sum += nums[i];
       }

       for (int i=0; i<n; i++) {
           res[i] = (nums[i] * i - prefix_sum) + (sum - prefix_sum - nums[i] * (n - i));
           prefix_sum += nums[i];
       }

       return res;
    }
};