class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>>ans(n-2, vector<int>(n-2, -1));
        
        for(int i=1; i<n-1; i++) {
            for(int j=1; j<n-1; j++) {
                int maxi = max({grid[i][j], grid[i-1][j], grid[i+1][j],
                        grid[i-1][j-1], grid[i+1][j+1], grid[i][j-1],
                        grid[i][j+1], grid[i-1][j+1], grid[i+1][j-1]});
                ans[i-1][j-1] = maxi;
            }
        }

        return ans;
    }
};