class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        map<char, int>mp;
        string ans = s;
        int n = s.size();
        for(int i=0; i<n ; i++) {
            ans[indices[i]] = s[i];
        }

        return ans;
    }
};