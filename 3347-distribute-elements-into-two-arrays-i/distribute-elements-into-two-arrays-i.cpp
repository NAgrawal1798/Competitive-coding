class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>ans1;
        vector<int>ans2;

        int n = nums.size();
        int i=0;
        ans1.push_back(nums[i++]);
        ans2.push_back(nums[i++]);

        while(i<n) {
            if(ans1[ans1.size() - 1] < ans2[ans2.size() - 1]) {
                ans2.push_back(nums[i++]);
            } else {
                ans1.push_back(nums[i++]);
            }
        }

        vector<int>ans = ans1;
        for(int j=0; j<ans2.size(); j++) {
            ans.push_back(ans2[j]);
        }

        return ans;
    }
};