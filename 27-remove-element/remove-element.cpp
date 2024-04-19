class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int index = 0;
       int n = nums.size();
       int count=0;
       for(int i=0; i<n; i++) {
            if(nums[i] == val) {
                count++;
            } else {
                nums[index++] = nums[i];
            }
       }
       return index;
    }
};