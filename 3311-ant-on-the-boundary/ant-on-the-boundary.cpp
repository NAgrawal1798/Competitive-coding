class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
       // over the iteration i need to check how many time totla sum becomes 0
       int sum = 0;
       int ans = 0;
        int n = nums.size();
       for(int i=0; i<n; i++) {
           sum += nums[i];
           if (sum ==0 ) {
               ans++;
           }
       }

       return ans; 
    }
};