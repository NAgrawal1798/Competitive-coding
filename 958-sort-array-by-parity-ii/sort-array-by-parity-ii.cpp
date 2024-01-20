class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int>even;
        vector<int>odd;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i]%2 ==0 ){
                even.push_back(nums[i]);
            } else {
                odd.push_back(nums[i]);
            }
        }

        vector<int>ans(nums.size());
        int j=0;
        int k=0;
        for (int i=0; i<nums.size(); i++) {
            if(i%2) {
                ans[i] = odd[j];
                j++;
            } else {
                ans[i] = even[k];
                k++;
            }
        }

        return ans;

    }
};