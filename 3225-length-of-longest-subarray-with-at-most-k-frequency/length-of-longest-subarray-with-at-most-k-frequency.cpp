class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int ans = 0;
        map<int,int>mp;

        int n = nums.size();
        while(j<n) {
            mp[nums[j]]++;
            if (mp[nums[j]] > k) {
                ans = max(ans, j-i);
                while(mp[nums[j]] >k && i<n) {
                    mp[nums[i]]--;
                    i++;
                }
            }
            j++;
        }
        ans = max(ans, j-i);

        return ans;
    }
};