class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n = nums.size();
        
        int digitSum = 0;
        int elementSum = 0;
        for (int i=0; i<n; i++) {
            elementSum += nums[i];
            int temp = nums[i];
            while(temp) {
                digitSum += temp%10;
                temp = temp/10;
            }
        }

        return abs(elementSum - digitSum);
    }
};