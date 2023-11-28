class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        double sum=0;
        double maxi = INT_MIN;
        while(j<nums.size()) {
            sum += nums[j];
            if (j-i+1 < k) {
                j++;
            } else {
                maxi = max(maxi , sum/k);
                sum -= nums[i];
                j++;
                i++;
            }
        }
        return maxi;
    }
};