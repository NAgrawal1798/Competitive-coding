class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int n= matrix.size();      //Number of rows
		int m= matrix[0].size() ;  //Number of columns
		
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++) {
                int res;
                if (i<1 || j<1) {
                    res = matrix[i][j];
                } else {
                    res = matrix[i-1][j-1];
                }

                if (res != matrix[i][j]) {
                    return false;
                }
            }
        }

        return true;
    
    }
};