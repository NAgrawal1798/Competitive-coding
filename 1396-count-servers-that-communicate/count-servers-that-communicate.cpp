class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<int>r(n,0);
        vector<int>c(m,0);

        for (int i=0; i<n; i++) {
            int cnt = 0;
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1) {
                    cnt++;
                }
            }
            r[i] = cnt;
        }

        for (int j=0; j<m; j++) {
            int cnt = 0;
            for (int i=0; i<n; i++) {
                if (grid[i][j] == 1) {
                    cnt++;
                }
            }
            c[j] = cnt;
        }

        int ans = 0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (r[i] + c[j] - 2 >0 && grid[i][j]==1) {
                    ans += 1;
                }
            }
        }

        return ans;
    }
};