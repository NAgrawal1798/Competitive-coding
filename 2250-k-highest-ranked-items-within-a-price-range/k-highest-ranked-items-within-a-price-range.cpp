class Solution {
public:
    // Algo
    // 1. Apply BFS
    // 2. Insert into vector
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,pair<int,int>>>q;
        q.push({0, {start[0], start[1]}});
        vector<vector<int>>visited(n, vector<int>(m,0));
        visited[start[0]][start[1]] = 1;

        vector<vector<int>>ans;

        vector<int>dr = {-1, 1, 0, 0};
        vector<int>dc = {0, 0, -1, 1};
        while(!q.empty()) {
            int x = q.front().second.first;
            int y = q.front().second.second;
            int steps = q.front().first;
            q.pop();

            if (grid[x][y] >= pricing[0] && grid[x][y] <= pricing[1]) {
                cout<<steps<<" "<<x<<" "<<y<<endl;
                ans.push_back({steps, grid[x][y], x, y});
            }

            for (int i=0; i<4; i++) {
                int newr = x + dr[i];
                int newc = y + dc[i];

                if (newr >=0 && newc >=0 && newr < n && newc < m && !visited[newr][newc] && grid[newr][newc] != 0 ) {
                    visited[newr][newc] = 1;
                    q.push({steps+1, {newr, newc}});
                }
            }
        }

        sort(ans.begin(), ans.end());

        vector<vector<int>>final_ans;
        int size = ans.size();
        int length = min(k, size);
        cout<<length<<endl;
        for (int i=0 ;i<length ;i++) {
            final_ans.push_back({ans[i][2], ans[i][3]});
        }

        return final_ans;
    }
};