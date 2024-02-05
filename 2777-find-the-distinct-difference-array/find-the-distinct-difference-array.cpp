class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int>prefix(nums.size());
        vector<int>suffix(nums.size());
        set<int>s;
        set<int>p;

        for (int i=0 ;i<nums.size(); i++) {
            s.insert(nums[i]);
            prefix[i] = s.size();
        }
        
        suffix[nums.size() - 1] = 0;
        p.insert(nums[nums.size() - 1]);
        for(int j=nums.size()-2; j>=0 ; j--) {
            suffix[j] = p.size();
            p.insert(nums[j]);
        }

        vector<int>ans(nums.size());
        for(int i=0; i<nums.size(); i++) {
            ans[i] = prefix[i] - suffix[i];
        }

        return ans;

    }
};