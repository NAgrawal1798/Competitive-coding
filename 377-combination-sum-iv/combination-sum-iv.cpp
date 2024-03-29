// int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
class Solution {
public:
// this function will return number of combinations to achieve sum==left...
    int get_combination(int left,vector<int>&nums,vector<int>&dp){
        if(left==0){
            // some how we have achieved our sum==target there left target==0
            return 1;
        }
        if(left<0){
            return 0;
        }
        if(dp[left]!=-1){
            // we know number of combinations corresponding to left..
            return dp[left];
        }
        int ans=0;
        for(auto ele:nums){
            // if we have ele.. left will be decresed by ele..
            ans+=get_combination(left-ele,nums,dp);
        }
        return dp[left]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1); // it will store number of combinations corresponding to each sum from 0-target...

        // initially left==target...
        return get_combination(target,nums,dp);

    }
};