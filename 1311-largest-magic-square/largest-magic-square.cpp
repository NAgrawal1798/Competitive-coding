#define ll long long
class Solution {
public:

    int check(vector<vector<int>>& grid,int x,int y,int s) {

        if (x+s>grid.size() || y+s>grid[0].size()) {
            return 1;
        }

        ll sum = 0;

        for (int k=0;k<s; k++) {
            sum += grid[x+k][y+k];
        }

        ll sum2= 0;

        for (int k=0;k<s;k++) {
            sum2 += grid[x-k+s-1][y+k];
        }

        if (sum2!= sum) {
            return 1;
        }

        for (int i=0; i<s; i++) {
            ll sumrow=0;
            for (int j=0;j<s;j++) {
                sumrow += grid[i+x][y+j];
            }
            ll sumcol=0;
            for (int j=0; j<s;j++) {
                sumcol += grid[x+j][y+i];
            }

            if (sumcol != sum || sumrow != sum) {
                return 1;
            }
        }

        return s;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans = 1;

        int n = grid.size();
        int m = grid[0].size();
        for (int i=0;i<n; i++) {
            for (int j=0;j<m;j++) {
               for (int k=1; k<=min(m,n); k++) {
                   int temp = check(grid,i,j,k);
                   ans=max(ans,temp);
               }
            }
        }

        return ans;
    }
};