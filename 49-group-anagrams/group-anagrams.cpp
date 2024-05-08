class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<string, vector<int>>mp;
        int n = strs.size();
        for(int i=0; i<n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }

        for(auto it: mp) {
            vector<string>temp;
            for(auto i: it.second) {
                temp.push_back(strs[i]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};