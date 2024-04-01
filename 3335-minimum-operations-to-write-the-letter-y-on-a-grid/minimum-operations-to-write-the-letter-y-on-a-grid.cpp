class Solution {
public:
    int getOperationCount(vector<vector<int>>& grid, int y, int notY) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i<= grid.size()/ 2 && (i==j || i+j == grid.size() - 1) || (i> grid.size()/2 && j == grid.size()/2)) {
                    if(y != grid[i][j]) {
                        ans++;
                    }
                } else {
                    if(notY != grid[i][j]) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        return min({getOperationCount(grid, 0 , 1),
        getOperationCount(grid, 0 , 2),
        getOperationCount(grid, 1 , 0),
        getOperationCount(grid, 1 , 2),
        getOperationCount(grid, 2 , 0),
        getOperationCount(grid, 2 , 1)});
    }
};