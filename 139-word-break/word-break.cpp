class Solution {
public:
    set<string>st;
    bool helper(string s, int index, vector<int> &dp) {
        // base case
        if(index == s.size()) {
            return true;
        }
        if (dp[index] != -1) {
            return dp[index];
        }

        for(int i=index; i<s.size(); i++) {
            if(st.count(s.substr(index, i - index + 1))) {
                if(helper(s, i + 1, dp)) {
                    return dp[index] = 1;
                }
            }
        }

        return dp[index] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        vector<int>dp(s.size(), -1);
        for(int i=0; i<n; i++) {
            st.insert(wordDict[i]);
        }
        return helper(s, 0, dp);
    }
};