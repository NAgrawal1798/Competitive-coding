class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans = 0;
        int maxFreq = 0;
        int n = nums.size();
        map<int,int>mp;

        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] > maxFreq) {
                maxFreq = mp[nums[i]];
                ans = mp[nums[i]];
            } else if(mp[nums[i]] == maxFreq) {
                ans += mp[nums[i]];
            }
        }

        return ans;
    }
};