class Solution {
public:
    vector<int>dr = {-1, 1, 0, 0};
    vector<int>dc = {0, 0, 1, -1};
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        visited[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();

        for(int k=0; k<4; k++) {
            int newr = i + dr[k];
            int newc = j + dc[k];
            if (newr >= 0 && newr < n && newc >= 0 && newc < m && (grid[newr][newc] == 1) && (visited[newr][newc] == 0)) {
                dfs(newr, newc, grid, visited);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));

        for (int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if (grid[i][j] == 1 && (i==0 || i== n-1 || j==0 || j==m-1) && visited[i][j] == 0) {
                    dfs(i, j, grid, visited);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if (i==0 || i==n-1 || j==0 || j== m-1) {
                    continue;
                }
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    ans++;
                }
            }
            cout<<endl;
        }

        return ans;
    }
};