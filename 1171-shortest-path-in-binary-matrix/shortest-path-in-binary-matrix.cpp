class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] != 0) {
            return -1;
        }

        // Use bfs to solve the problem
        vector<vector<int>>vis(n , vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        vis[0][0] = 1;

        while(!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            if (x == n-1 && y == m-1) {
                return steps;
            }
            for(int i=-1; i<=1; i++) {
                for(int j=-1; j<=1; j++) {
                    int newr = x + i;
                    int newc = y + j;
                    if(newr >= 0 && newr < n && newc >= 0 && newc < m && vis[newr][newc] == 0 && grid[newr][newc] == 0) {
                        vis[newr][newc] = 1;
                        q.push({{newr, newc}, steps+1});
                    }
                }
            }
        }

        return -1;
    }
};