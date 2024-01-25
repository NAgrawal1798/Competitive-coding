class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& matrix) {
        if(i == matrix.size()) {
            return 0;
        }

        if(j < 0 || j>= matrix[0].size()) {
            return INT_MAX;
        }

        return matrix[i][j] + min({helper(i+1, j, matrix), helper(i+1, j-1, matrix), helper(i+1, j+1, matrix)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int result=INT_MAX;
        // for(int j=0; j<matrix[0].size(); j++) {
        //     result = min(result, helper(0, j, matrix));
        // }

        // return result;

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m,INT_MAX));

        for(int j=0; j<m;j ++) {
            dp[0][j] = matrix[0][j];
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                int left = INT_MAX;
                int right = INT_MAX;
                if(j-1 >= 0) {
                    left = matrix[i][j] + dp[i-1][j-1];
                }
                if (j+1 < m) {
                    right =  matrix[i][j] + dp[i-1][j+1];
                }
                dp[i][j] = min({dp[i][j], left, right, matrix[i][j] + dp[i-1][j]});
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }

        int mini = INT_MAX;
        for(int j=0; j<m;j++) {
            mini = min(mini, dp[n-1][j]);
        }
        return mini;
    }   
};