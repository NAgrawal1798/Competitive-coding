class Solution {
public:

    bool helper(vector<vector<char>>& grid, char c) {
        //diaganols

        // rows and cols
        for (int i=0; i<3; i++) {
            if (grid[i][0] == c && grid[i][1] == c && grid[i][2] == c) {
                return true;
            }
            if (grid[0][i]== c && grid[1][i] == c && grid[2][i] == c) {
                return true;
            }
        }
        if (grid[0][2] == c && grid[1][1] == c && grid[2][0] == c) {
            return true;
        }  
        if (grid[0][0] == c && grid[1][1] == c && grid[2][2] == c) {
            return true;
        }  

        return false;

    }
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>>grid(3, vector<char>(3,'.'));

        int n = moves.size();
        
        for (int i=0; i<n; i++) {
            if (i%2==0) {
                grid[moves[i][0]][moves[i][1]] = 'X';   
            } else {
                grid[moves[i][0]][moves[i][1]] = 'O';   
            }

        }

        bool checkA = helper(grid, 'X');
        bool checkB = helper(grid, 'O');

        int count=0;

        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (grid[i][j] == '.') {
                    count++;
                }
            }
        }


        if (!checkA && !checkB && count==0) {
            return "Draw";
        }
        if (checkA) {
            return "A";
        }
        if (checkB) {
            return "B";
        }
        return "Pending";
    }
};