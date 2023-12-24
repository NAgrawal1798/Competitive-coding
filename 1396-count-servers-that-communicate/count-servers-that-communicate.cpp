class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int i,j,m = grid.size(), n = grid[0].size();
        vector<int> r(m,0),c(n,0);
        int x = 0;
        for(i = 0; i < m; i++){
            x = 0;
            for(j = 0; j < n; j++){
                x += grid[i][j];
            }
            r[i] = x;
        }
        for(j = 0; j < n; j++){
            x = 0;
            for(i = 0; i < m; i++){
                x += grid[i][j];
            }
            c[j] = x;
        }
        int ans = 0;
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                // cout<<r[i]<<" "<<c[j]<<" "<<grid[i][j]<<endl;
                ans += (r[i]+c[j]-2>=1 && grid[i][j]);   
            }
        }
        return ans;
    }
};