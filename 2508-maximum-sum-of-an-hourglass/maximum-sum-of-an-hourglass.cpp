class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i+2 < n && j+2 < m) {
                    int sum = 0;
                    for(int k=0; k<3; k++) {
                        sum += grid[i][j+k] + grid[i+2][j+k];
                    }
                    sum += grid[i+1][j+1];
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
};