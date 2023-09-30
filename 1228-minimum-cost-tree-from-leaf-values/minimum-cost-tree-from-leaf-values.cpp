class Solution {
public:
    int dp[42][42];

    int solve(int i, int j, vector<int>& arr) {
        if(i==j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int mn = INT_MAX;

        for (int k=i; k<j; k++) {
            int leftMax = 0;
            int rightMax = 0;
            for (int id=i; id<=k; id++) {
                leftMax = max(leftMax, arr[id]);
            }
            for (int id=k+1; id<=j; id++) {
                rightMax = max(rightMax, arr[id]);
            }
            mn = min(mn, leftMax*rightMax + solve(i,k,arr) + solve(k+1,j,arr));
        }
        return dp[i][j] = mn;
    }

    int mctFromLeafValues(vector<int>& arr) {
        memset(dp, -1, sizeof(dp));
        return solve(0, arr.size()-1, arr);
    }
            
};