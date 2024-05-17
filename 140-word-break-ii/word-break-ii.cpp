class Solution {
public:
    // backtracking code
    void helper(string s, set<string>& st, string sen, int index,
    vector<string>&ans) {
        //base case
        if (index == s.size()) {
            ans.push_back(sen);
            return;
        }

        // recursion loop
        for(int i=index; i<=s.size(); i++) {
            string word = s.substr(index, i - index);
            if (st.count(word) > 0) {
                helper(s, st, sen == "" ? word : sen + " " +  word, i, ans);
            }
        }

        return;

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string>st(wordDict.begin(), wordDict.end());
        vector<string>ans;
        string sen; // for sentence
        helper(s, st, sen, 0, ans);
        return ans;
    }
};