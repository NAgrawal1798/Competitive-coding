class Solution {
public:
    int minimumCost(vector<int>& nums) {
        // can run brute force to this approach
        int n = nums.size();
        // find the minimum 3 elements from the array
        int ans = nums[0];

        vector<int>temp;
        for(int i=1; i<n; i++) {
            temp.push_back(nums[i]);
        }

        sort(temp.begin(), temp.end());

        return ans + temp[0] + temp[1];
    }
};