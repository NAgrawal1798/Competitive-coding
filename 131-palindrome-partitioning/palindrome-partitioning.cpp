class Solution {
public:
    // dp solution kind of backtracking
    // cut it or not cut it
    // Its more like to find the all possible subset which is 
    // being done by the backtracking
    bool check(int i, int j, string s) {
        while(i<=j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    } 
    void helper(string s , int index, vector<vector<string>>&ans, vector<string>&path) {
        if (index == s.length()) {
            ans.push_back(path);
            return;
        }
        for (int i = index; i< s.length(); i++) {
            if (check(index, i, s)) {
                path.push_back(s.substr(index,i-index+1));
                helper(s, i + 1, ans, path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        helper(s, 0, ans, path);
        return ans;
    }
};