class Solution {
public:
    // Apply BFS
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n, vector<int>(m,0));
        queue<pair<int,int>>q;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1) {
                    visited[i][j]=1;
                    q.push({i,j});
                }
            }
        }

        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,-1,1};
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k=0; k<4; k++) {
                int newr = i + dr[k];
                int newc = j + dc[k];
                // cout<<newr<<" "<<newc<<endl;
                if (newr < 0 || newr >= n || newc <0 || newc >= m || visited[newr][newc] == 1) {
                    continue;
                }
                // cout<<"is anything"<<endl;
                grid[newr][newc] = 1 + grid[i][j];
                visited[newr][newc] = 1;
                q.push({newr, newc});
            }
        }

        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                ans = max(ans, grid[i][j]);
            }
        }
        if (ans == 1) {
            return -1;
        }
        return ans-1;
    }
};