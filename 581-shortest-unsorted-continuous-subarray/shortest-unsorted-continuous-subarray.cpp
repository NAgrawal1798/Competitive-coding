class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>temp;
        temp = nums;
        int n = nums.size();
        sort(temp.begin(), temp.end());
        int pref = -1;
        int suff = -1;
        for(int i=0; i<n; i++) {
            if(nums[i] != temp[i]) {
                pref = i;
                break;
            }
        }

        for(int i=n-1; i>=0; i--) {
            if(nums[i] != temp[i]) {
                suff = i;
                break;
            }
        }

        if(pref == -1 || suff == -1) {
            return 0;
        }
        return suff - pref+1;

    }
};