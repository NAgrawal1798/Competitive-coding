class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int>s;
        int i=0;
        int j=0;
        int n = nums.size();
        int sum=0;
        int max_sum = 0;

        while(j<n) {
            if (s.count(nums[j]) > 0) {
                while(s.count(nums[j]) > 0) {
                    s.erase(nums[i]);
                    sum -= nums[i];
                    cout<<sum<<endl;
                    i++;
                }
            } else {
                s.insert(nums[j]);
                sum += nums[j];
                max_sum = max(max_sum, sum);
                j++;
            }
        }

        return max_sum;
    }
};