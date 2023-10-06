class Solution {
public:
    int longestPalindrome(string s) {
        int length = s.size();

        map<char, int> mp;

        for (int i = 0; i < length; i++) {
            mp[s[i]]++;
        }

        int ans = 0;
        bool isSingleChar = false;

        for (auto it : mp) {
            if (it.second % 2 == 0) {
                ans += it.second;
            } else {
                ans += it.second - 1; // Contribute even-length palindrome
                isSingleChar = true;   // Set the flag for a single character in the middle
            }
        }

        // If there's at least one single character in the middle, add it to the answer.
        if (isSingleChar) {
            ans++;
        }

        return ans;
    }
};
