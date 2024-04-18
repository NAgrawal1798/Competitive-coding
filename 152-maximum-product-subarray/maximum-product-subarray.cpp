class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        if(n==1) {
            return nums[0];
        }
        vector<int>pref(n);
        vector<int>suff(n);
        pref[0] = nums[0];
        suff[n-1] = nums[n-1];
        int maxi = INT_MIN;

        for(int i=0; i<n; i++) {
            maxi = max(maxi, nums[i]);
        }
        for(int i=1; i<n; i++) {
            if(pref[i-1] == 0) {
                pref[i] = nums[i];
                maxi = max(maxi, nums[i]);
            } else {
                int val = pref[i-1] * nums[i];
                pref[i] = val;
                maxi = max(maxi, val);
            }
        }

        for(int i=n-2; i>=0; i--) {
            if(suff[i+1] == 0) {
                suff[i] = nums[i];
                maxi = max(maxi, nums[i]);
            } else {
                int val = suff[i+1] * nums[i];
                suff[i] = val;
                maxi = max(maxi, val);
            }
        }

        return maxi;
    }
};