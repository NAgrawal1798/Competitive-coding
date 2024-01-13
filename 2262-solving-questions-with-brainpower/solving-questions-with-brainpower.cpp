class Solution {
public:
    // kind of a dp question
    // take or not take
    long long helper(vector<vector<int>>& questions, int index, vector<long long>&dp) {
        // base case
        if (index >= questions.size()) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }

        long long take = questions[index][0] + helper(questions, questions[index][1] + index + 1, dp);
        long long not_take = 0 + helper(questions, index+1, dp);

        return dp[index] =  max(take, not_take);

    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>dp(questions.size(), -1);
        long long ans = helper(questions, 0, dp);
        return ans;
    }
};