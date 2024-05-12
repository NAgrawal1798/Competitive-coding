class Solution {
public:
    string minWindow(string s, string t) {
        // expand and shrink concept;
        string ans;
        int left = 0;
        int right = 0;
        int minStart = 0;
        int minLen = INT_MAX;
        int m = s.size();
        int n = t.size();
        map<char, int>mp;
        for(int k=0; k<n; k++) {
            mp[t[k]]++;
        }

        int remaining = t.length();
        while(right != m) {
            if(mp.find(s[right]) != mp.end()) {
                mp[s[right]]--;
                if(mp[s[right]] >= 0) { // Checking if the character at right pointer is needed
                    remaining--;
                }
            }
            right++;

            while(remaining == 0) {
                if(right - left < minLen) {
                    minLen = right - left;
                    minStart = left;
                }
                if(mp.find(s[left]) != mp.end()) {
                    mp[s[left]]++;
                    if(mp[s[left]] > 0) { // Checking if the character at left pointer is no longer present in window
                        remaining++;
                    }
                }
                left++;
            }
}

        return minLen < INT_MAX ? s.substr(minStart, minLen) : "";
    }
};