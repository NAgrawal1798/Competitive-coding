class Solution {
public:
    bool isValid(string s) {
        if (s[0] == '0') {
            return false;
        }
        if (s.size() > 2) {
            return false;
        }
        int num = stoi(s);
        return num >= 1 && num <= 26;
    }

    int helper(string &s, int index, vector<int>& dp) {
        if (index == s.size()) {
            return 1; // Reached the end, one valid decoding
        }
        if (dp[index] != -1) {
            return dp[index]; // Return the value if it's already calculated
        }

        int ways = 0;
        for (int i = index; i < s.size(); i++) {
            if (isValid(s.substr(index, i - index+1))) {
                ways += helper(s, i+1, dp);
            }
        }

        dp[index] = ways; // Store the result in the DP array
        return ways;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1); // Initialize DP array with -1
        return helper(s, 0, dp);
    }
};
