#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));

        queue<pair<int, int>> q;

        // Add all 0s to the queue and set their distance to 0
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    distance[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // Check all four directions
            for (int k = 0; k < 4; ++k) {
                int newR = r + dr[k];
                int newC = c + dc[k];

                // Check if the new indices are within bounds
                if (newR >= 0 && newR < n && newC >= 0 && newC < m) {
                    // If the current distance is greater than the potential new distance
                    if (distance[newR][newC] > distance[r][c] + 1) {
                        distance[newR][newC] = distance[r][c] + 1;
                        q.push({newR, newC}); // Add to queue for further exploration
                    }
                }
            }
        }

        return distance;
    }
};
