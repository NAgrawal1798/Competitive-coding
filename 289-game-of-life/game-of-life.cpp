class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>ans(n, vector<int>(m, 0));

        vector<int>dr = {1, 0, -1, -1, -1, 0, 1, 1};
        vector<int>dc = {-1, -1, -1, 0, 1, 1, 1, 0};

        for(int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int sign = board[i][j];
                int count_ones = 0;
                for(int k=0; k< 8; k++) {
                    int newr = i + dr[k];
                    int newc = j + dc[k];
                    if (newr >= 0 && newr < n && newc >= 0 && newc < m) {
                        if (board[newr][newc] == 1) {
                            count_ones++;
                        }
                    }
                }
                // cases
                if (count_ones < 2) {
                    sign = 0;
                }
                if (count_ones == 2  && count_ones == 3) {
                   // no change
                }
                if (count_ones > 3) {
                    sign = 0;
                }
                if (count_ones == 3) {
                    sign =1;
                }

                ans[i][j] = sign;
            }
        }

        board = ans;
    }
};