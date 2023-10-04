class Solution {
public:
    string longestPalindrome(string s) {
       int n = s.size();

       vector<vector<bool>>dp(n, vector<bool>(n, false));

       int ans = 0;
       int start;

       for (int iteration=0; iteration<n; iteration++) {
           for (int j=0; j+iteration<n; j++) {
               if (iteration==0) {
                   dp[j][j] = true;
               } else if (iteration==1 && s[j] == s[j+1]) {
                   dp[j][j + 1] = true;
               } else if (iteration > 1 && dp[j+1][j+iteration -1] && s[j] == s[j + iteration]) {
                   dp[j][j + iteration] = true;
               }

               if (dp[j][j+iteration]) {
                   ans = iteration;
                   start = j;
               }
           }
       }

       return s.substr(start, ans+1);
    }
};