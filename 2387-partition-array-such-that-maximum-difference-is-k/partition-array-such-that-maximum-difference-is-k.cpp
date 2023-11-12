class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());

        int ans = 0;

        int i=0;
        int j=0;
        int n = nums.size();

        while(j<n) {
            if ((nums[i] - nums[j]) <= k) {
                j++;
            } else {
                ans++;
                i=j;
            }
        }
        ans++;

        return ans;
    }
};