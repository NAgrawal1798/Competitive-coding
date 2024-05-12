class Solution {
public:
    bool check(string s, int i, int j) {
        while(i<=j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void helper(string s, int index,vector<string>& path, vector<vector<string>>&ans) {
        if (index == s.size()) {
            ans.push_back(path);
            return;
        }
        for(int i=index; i<s.size(); i++) {
            if (check(s, index, i)) {
                path.push_back(s.substr(index, i-index + 1));
                helper(s, i+1, path, ans);
                path.pop_back();
            }
        }

        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        helper(s, 0, path, ans);
        return ans;
    }
};