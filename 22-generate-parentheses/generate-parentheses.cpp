class Solution {
public:
    void helper(int n ,int open , int closed, string s , vector<string>&ans) {
        if (closed > open) {
            return;
        }
        if ((open + closed == 2*n)) {
            ans.push_back(s);
        }
        // add open brackets
        if (open < n) {
            s += "(";
            open++;
            helper(n, open, closed, s, ans);
            open--;
            s.pop_back();
        }
        
        // add closed brackets
        if (closed < n) {
            s += ")";
            closed++;
            helper(n, open, closed, s, ans);
            closed--;
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        // bactracking problem
        int open = 0;
        int closed = 0;
        string s = "";
        vector<string>ans;
        helper(n, open ,closed, s, ans);
        return ans;
    }
};