class Solution {
public:
    int solve(vector<vector<int>>& grid ) {
        // brute force approach
        // kind of backtracking and recursion
        // at every step i will check whether all has elements or not
        // bfs
        int zero = 0;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(grid[i][j] == 0) {
                    zero++;
                }
            }
        }
        if(zero == 0) {
            return 0;
        }
        int cnt = INT_MAX;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(grid[i][j] == 0) {
                    for(int nRow = 0; nRow<3; nRow++) {
                        for(int nCol=0; nCol<3; nCol++) {
                            if(grid[nRow][nCol] > 1) {
                                int moves = abs(nRow-i)+abs(nCol-j);
                                grid[nRow][nCol]--;
                                grid[i][j]++;
                                cnt=min(cnt,moves+solve(grid));
                                grid[nRow][nCol]++;
                                grid[i][j]--;
                            }
                        }
                    }
                }
            }
        }

        return cnt;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        return solve(grid);
    }
};