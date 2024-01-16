class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i=0;

        int sum = 0;
        int n = mat.size();
        for (int i=0; i<n; i++) {
            sum += mat[i][i] + mat[i][n-1-i];
        }

        if (n%2) {
            sum -= mat[n/2][n/2];
        }
        cout<<mat[n/2][n/2]<<endl;
        return sum;
    }
};