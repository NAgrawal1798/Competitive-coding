class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                int count=4;
                if (i-1 >=0 && grid[i-1][j] == 1) {
                    count--;
                }
                if (j-1 >=0 && grid[i][j-1] == 1) {
                    count--;
                }
                if (i+1 <= grid.size()-1 && grid[i+1][j] == 1){
                    count--;
                }
                if (j+1 <= grid[0].size()-1 && grid[i][j+1] == 1){
                    count--;
                }
                ans += count;
            }
        }
        return ans;
    }
};