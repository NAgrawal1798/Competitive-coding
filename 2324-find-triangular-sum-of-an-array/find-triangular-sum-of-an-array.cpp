class Solution {
public:
    int triangularSum(vector<int>& nums) {
        // create a new vector everytime

        int n = nums.size();
        while(n!=1) {
            vector<int>temp;
            for(int i=0; i<n-1; i++) {
                temp.push_back((nums[i] + nums[i+1])%10);
            }
            n = temp.size();
            nums=temp;
        }

        return nums[0];
    }
};