class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));

        for(int j=0; j<m; j++) {
            int maxi =INT_MIN;
            vector<int>minus_ones;
            for(int i=0; i<n; i++) {
                if(nums[i][j] != -1) {
                    ans[i][j] = nums[i][j];
                    maxi = max(maxi, nums[i][j]);
                } else {
                    minus_ones.push_back(i);
                }
            }
            for(int k=0; k<minus_ones.size(); k++) {
                ans[minus_ones[k]][j] = maxi;
            }
        }

        return ans;
    }
};