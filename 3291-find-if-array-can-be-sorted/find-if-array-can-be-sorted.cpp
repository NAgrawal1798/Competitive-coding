class Solution {
public:
    bool canSortArray(vector<int>& nums) {
       int n = nums.size();
       int start=0;

       for(int i=1; i<n; i++) {
           int a = __builtin_popcount(nums[i-1]);
           int b = __builtin_popcount(nums[i]);

           if(a!=b) {
               sort(nums.begin() + start, nums.begin() + i);
               start=i;
           }
       }

       // sort the last segment
       sort(nums.begin() + start, nums.end());

       // Check if the array is sorted
       for(int i=1; i<n; i++) {
           if (nums[i] < nums[i-1]) {
               return false;
           }
       }

       return true;
    }
};