class Solution {
public:

    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int,int>>&q) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || i>=n || j< 0 || j >= m || grid[i][j] == -1 || grid[i][j] == 0 ) {
            return;
        }
        grid[i][j] = -1;
        q.push({i,j});
        dfs(grid, i+1, j,q);
        dfs(grid, i-1, j,q);
        dfs(grid, i, j-1,q);
        dfs(grid, i, j+1,q);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        bool flag = true;
        queue<pair<int,int>>q;

        for (int i=0; i<n; i++) {
            for (int j=0;j<m; j++) {
                if (grid[i][j] == 1 && flag) {
                    flag = false;
                    dfs(grid, i, j, q);
                }
            }
        }
        int ans= 0;
        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,-1,1};

        while(!q.empty()) {
            int a = q.size();
            while(a--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for (int k=0; k<4; k++) {
                    int newr = i + dr[k];
                    int newc = j + dc[k];
                    if (newr < 0 || newr >= n || newc < 0 || newc >= m || grid[newr][newc] == -1) {
                        continue;
                    }
                    if (grid[newr][newc] == 1) {
                        return ans;
                    }
                    grid[newr][newc] = -1;
                    q.push({newr, newc});
                }
            }
            ans++;
        }

        return ans;

    }
};