class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int i=0;
      int j=0;
      int n = s.size();
      map<char, int>mp;
      int ans = 0;

      while(j<n) {
        mp[s[j]]++;
        while(i<n && mp[s[j]] > 1) {
            mp[s[i]]--;
            i++;
        }
        ans = max(ans, j-i + 1);
        j++;
      }

      return ans;
    }
};