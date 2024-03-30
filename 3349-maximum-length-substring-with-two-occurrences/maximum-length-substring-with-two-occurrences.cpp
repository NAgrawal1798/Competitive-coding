class Solution {
public:
    int maximumLengthSubstring(string s) {
        // take a map
        map<char, int>mp;
        int n = s.size();
        int i=0; 
        int j=0;
        int ans = 0;
        while(j < n) {
            mp[s[j]]++;
            if(mp[s[j]] > 2) {
                while(i < n && mp[s[j]] > 2) {
                    mp[s[i]]--;
                    i++;
                }
            }
            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};