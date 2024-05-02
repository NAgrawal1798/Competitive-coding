class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int>mp;
        int n = s.size();
        int m = t.size();
        if(n != m) {
            return false;
        }

        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }

        for(int j=0; j<m; j++) {
            mp[t[j]]--;
        }

        for(auto it: mp) {
            if(it.second != 0) {
                return false;
            }
        }

        return true;
    }
};