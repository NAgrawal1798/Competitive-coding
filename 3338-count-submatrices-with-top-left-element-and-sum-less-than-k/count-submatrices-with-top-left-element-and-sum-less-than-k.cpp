class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        // prefix sum
        // horizontal row
        int n = grid.size();
        int m = grid[0].size();
        for(int i=1; i<n; i++) {
            grid[i][0] += grid[i-1][0];
        }

        for(int j=1; j<m ;j++) {
            grid[0][j] += grid[0][j-1];
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<m ;j++) {
                grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
            }
        }

        int count=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] <= k) {
                    count++;
                }
            }
        }

        return count;
        // vertical col
    }
};