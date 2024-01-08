class Solution {
public:
    int dp[1001][1001];
    // find all possible subsequence and calcaulte the dp
    int solve(int currentInd, int currentTarInd, string s, string t) {
        // base case
        if (currentTarInd  >= t.length()) {
            return 1;
        }
        if (currentInd >= s.length()) {
            return 0;
        }
        if (dp[currentInd][currentTarInd] != -1) {
            return dp[currentInd][currentTarInd];
        }

        int res1 = solve(currentInd + 1, currentTarInd, s, t);
        if (s[currentInd] == t[currentTarInd]) {
            res1 += solve(currentInd + 1, currentTarInd + 1, s, t);
        }
        return dp[currentInd][currentTarInd] = res1;
    }
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, t);
    }
};