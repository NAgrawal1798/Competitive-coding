class Solution {
public:
    // We can use dp solution
    // vector<vector<vector<int>>> dp;
    
    int helper(int a, int b, int c) {
        if (a <= 0 && b <= 0) return 0;
        if (a <= 0 && c <= 0) return 0;
        if (b <= 0 && c <= 0) return 0;
        
        // if (dp[a][b][c] != -1) {
        //     return dp[a][b][c];
        // }
        
        int score = 0;
        score = max(score, (a > 0 && b > 0) ? 1 + helper(a - 1, b - 1, c) : 0);
        score = max(score, (b > 0 && c > 0) ? 1 + helper(a, b - 1, c - 1) : 0);
        score = max(score, (a > 0 && c > 0) ? 1 + helper(a - 1, b, c - 1) : 0);
        
        // dp[a][b][c] = score;
        
        return score;
    }

   int maximumScore(int a, int b, int c) {
    if (a < b)
        return maximumScore(b, a, c);
    if (b < c)
        return maximumScore(a, c, b);
    return b == 0 ? 0 : 1 + maximumScore(a - 1, b - 1, c); 
}
};
