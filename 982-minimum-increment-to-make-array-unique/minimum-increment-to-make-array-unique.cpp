class Solution {
public:
    // use of mp
    int minIncrementForUnique(vector<int>& nums) {

        int maxVal = 0;
        for (int x : nums) {
            maxVal = max(maxVal, x);
        }

       map<int,int>mp;
       vector<int>cnt(nums.size() + maxVal, 0);

        int n = nums.size();
       for (int i=0; i<n; i++) {
           mp[nums[i]]++;
           cnt[nums[i]] = 1;
       }

       int ans = 0;
       for (auto it: mp) {
            if (it.second > 1) {
                // write the logic to increment it.
                for (int j=1; j<it.second; j++) {
                    int k = it.first;
                    while(cnt[k] != 0) {
                        k++;
                        ans++;
                    }
                    cnt[k] = 1;
                }
            }
       }

       return ans;
    }
};