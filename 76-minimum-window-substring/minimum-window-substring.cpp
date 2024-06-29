class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int>mp;
        int n = s.size();
        int m = t.size();

        int left = 0;
        int right = 0;
        for (int i=0; i<m; i++) {
            mp[t[i]]++;
        }
        int remaining = m;
        int minStart = 0;
        int minLen = INT_MAX;   
        while(right < n) {
            if (mp.find(s[right]) != mp.end()) {
                mp[s[right]]--;
                if (mp[s[right]] >= 0) {
                    remaining--;
                }
            }
            right++;
            while(remaining == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    minStart = left;
                }

                if (mp.find(s[left]) != mp.end()) {
                    mp[s[left]]++;
                    if (mp[s[left]] > 0) {
                        remaining++;
                    }
                }
                left++;
            }
        }

        return minLen < INT_MAX ? s.substr(minStart, minLen) : "";
    }
};