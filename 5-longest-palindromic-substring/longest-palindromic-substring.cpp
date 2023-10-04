class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(s.size(), vector<bool>(n, false));
        int ans=0, start;
        for(int i=0; i<n; ++i)
            for(int j=0; j+i<n; ++j){
                if(i==0)    dp[j][j+i] = true;
                else if(i==1 and s[j]==s[j+i]) dp[j][j+i] = true;
                else if(i>1 and s[j]==s[j+i] and dp[j+1][j+i-1]) dp[j][j+i] = true;
                if(dp[j][j+i])  ans = i, start=j;
            }
        return s.substr(start,ans+1);
    }
};