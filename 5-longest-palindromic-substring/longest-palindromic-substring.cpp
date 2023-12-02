class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans;
        int maxi = 0;
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // we have to traverse diagonals and above diagonals i.e.
        // 0,0 -> 1,1 -> 2, 2-> 3, 3 ....
        // 0,1 -> 1, 2 -> 2, 3 -> 3, 4 ...
        // 0,2 -> 1, 3 -> 2, 4 -> 3,5 ...
        for(int diff = 0; diff < n; diff++){
            for(int i = 0, j = i + diff; j < n; i++, j++){
                // diagonal elements are palindrome
                if(i == j){
                    dp[i][j] = 1;
                }
                // 2 digits are also palindrome having same i and j
                else if(diff == 1){
                    dp[i][j] = (s[i] == s[j]) ? 2 : 0;
                }
                else {
                    // when outer strings are palindrome and inner strings are also palindrome then consider it as palindrome
                    // aabaa
                    // ^   ^
                    // |   |
                    // i. .j
                    if(s[i] == s[j] && dp[i+1][j-1] > 0){
                        dp[i][j] = 2 + dp[i+1][j-1];
                    }
                }
                
                if(dp[i][j]){
                    if(maxi < j-i+1){
                        // update longest palindrome
                        maxi = j-i+1;
                        ans = s.substr(i, maxi);
                        // here i is starting point and maxi is length of substr
                    }
                }
            }
        }
        return ans;
    }
};