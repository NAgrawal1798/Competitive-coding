class Solution {
public:
    vector<int>dr = {-1, 1, 0 , 0};
    vector<int>dc = {0, 0, -1, 1};
    void helper(vector<vector<char>>& board, int i, int j, vector<vector<int>>& visited) {
        visited[i][j] = 1;
         int n = board.size();
        int m = board[0].size();

        for (int k=0; k<4; k++) {
            int newr = i + dr[k];
            int newc = j + dc[k];
             cout<<newr<<" "<<newc<<endl;
            if (newr >= 0 && newc >= 0 && newr <n && newc <m && !visited[newr][newc] && board[newr][newc] == 'O') {
                // cout<<newr<<" "<<newc<<endl;
                board[newr][newc] = '-';
                helper(board, newr, newc, visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();
        vector<vector<char>>temp  = board;
        vector<vector<int>>visited(n, vector<int>(m,0));

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if ((i==0 || i==n-1 || j==0 || j==m-1) && !visited[i][j] && temp[i][j] == 'O') {
                    temp[i][j] = '-';
                    helper(temp, i, j, visited);
                }
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (temp[i][j] != '-') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};