class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int countZeroes = 0;

        for (int i=0; i< nums.size(); i++) {
            if (nums[i] == 0) {
                countZeroes++;
            }
        }

        int n = nums.size();

        int i=0;
        int j=0;

        while(j<n) {
            if (nums[j]!=0 ) {
                nums[i] = nums[j];
                i++;
                j++;
            } else {
                j++;
            }
        }

        int start = n-countZeroes;
        if (start >=0) {
        for (int k=start; k<n;k++) {
            nums[k] = 0;
        }
        }
    }
};