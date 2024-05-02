class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                t += s[i];
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                t += 'a' + s[i] - 'A';
            } else if (s[i] >= '0' && s[i] <= '9') {
                t += s[i];
            }
        }

        string rev = t;
        reverse(rev.begin(), rev.end());
        return rev == t;
    }
};