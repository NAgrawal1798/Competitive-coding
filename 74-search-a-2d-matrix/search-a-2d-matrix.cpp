class Solution {
public:
    // Working solution
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>firstCol;

        for (int i=0; i<n; i++) {
            firstCol.push_back(matrix[i][0]);
        }

        int rowIndex = upper_bound(firstCol.begin(), firstCol.end(), target) - firstCol.begin()-1;

        if (rowIndex == -1) {
            return false;
        }

        if (firstCol[rowIndex] == target) {
            return true;
        }



        vector<int>row;

        for (int j=0; j<m;j++) {
            row.push_back(matrix[rowIndex][j]);
        }
        cout<<rowIndex<<endl;

        int colIndex = upper_bound(row.begin(), row.end(), target) - row.begin() - 1;

        cout<<colIndex<<endl;

        if (row[colIndex] == target) {
            return true;
        }

        return false;

    }
};