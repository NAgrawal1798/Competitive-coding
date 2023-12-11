class Solution {
public:
    int minMoves2(vector<int>& nums) {


      sort(nums.begin(),nums.end());
      int n=nums.size();
      int mid = n/2;
      int eq=nums[mid];
      int res=0;
      for(auto i:nums){
          res+=abs(eq-i);
      }  
      return res; 
    }
};