class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 1;
        while(i<nums.size() && nums[i]==nums[0])i++;
        int res = (i+1)/2;
        for(;i<nums.size();i++){
            if(nums[i] % nums[0] !=0 ) return 1;
        }
        return res;
    }
};