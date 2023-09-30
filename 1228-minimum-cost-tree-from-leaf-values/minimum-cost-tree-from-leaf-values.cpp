class Solution {
    int n;
    vector<vector<int>> dp;
public:
    int mctFromLeafValues(vector<int>& arr) {
        n = arr.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return solve(arr, 0, n-1);
    }
    
    int solve(vector<int> &arr, int i, int j) {
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k=i; k<j; k++) {
            int left = solve(arr, i, k);
            int right = solve(arr, k+1, j);
            ans = min(ans, (*max_element(arr.begin()+i, arr.begin()+k+1)) * (*max_element(arr.begin()+k+1, arr.begin()+j+1)) + left + right);
        }
        return dp[i][j] = ans;
    }
};