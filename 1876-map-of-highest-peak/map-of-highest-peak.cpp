class Solution {
public:
    // Apply bfs 
    // Increase height on every step.
    // Iterate ove the mat to find the maxiumum ans
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>>visited(n, vector<int>(m,0));

        queue<pair<int,int>>q;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (isWater[i][j] == 1) {
                    visited[i][j] = 1;
                    q.push({i,j});
                    isWater[i][j]=0;
                }
            }
        }

        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,-1,1};
        while(!q.empty()) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for (int k=0; k<4; k++) {
                    int newr = i + dr[k];
                    int newc = j + dc[k];
                    if (newr < 0 || newr >= n || newc >=m || newc <0 || visited[newr][newc] == 1 
                    || isWater[newr][newc] != 0) {
                        continue;
                    }
                    isWater[newr][newc] =  1 + isWater[i][j];
                    q.push({newr, newc});
                    visited[newr][newc] = 1;
                }
        }
        return isWater;
    }
};