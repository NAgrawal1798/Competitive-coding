class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;

        int size = nums.size();
        for (int i=0; i<size; i++) {
            ans.push_back(1);
        }

        for (int i=0; i<size; i++) {
            int j=i;

            while(j>=0) {
                if (nums[j] < nums[i]) {
                    ans[i] = max(ans[i], ans[j] + 1);
                }
                j--;
            }
        }

        int final_ans = ans[0];

        for (int i=0; i<size; i++) {
            final_ans = max(ans[i], final_ans);
        }

        return final_ans;
    }
};