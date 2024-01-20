class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i=0,j=0,sm=0,ans=0;
        int n=nums.size();
        if(goal==0)
        {
            while(j<n)
            {
                while(i<=j && nums[j])
                {
                    i++;
                }
                ans+=j-i+1;
                j++;
            }
            return ans;
        }
        while(j<n){
            sm+=nums[j];

            while(sm>goal){
                sm-=nums[i];
                i++;
            }
            if(sm==goal){
                ans++;
            }
            int x=i;
            while(nums[x]==0 && sm==goal){
                ans++;
                x++;
            }
            j++;
        }
        // while(sm>=goal && i<n){
        //     sm-=nums[i];
        //     i++;
        //     if(sm==goal) ans++;
        // }
        return ans;
    }
};