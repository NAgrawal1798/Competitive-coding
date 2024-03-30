class Solution {
public:
    long long countSubstrings(string s, char c) {
        // find the points of char c in the string
        // for 4 it will be 6 = (n*(n-1))/2
        // a..a..a..a

        long long ans = 0;
        long long occ = 0;
        long long n = s.size();
        for(long long i=0; i<n; i++) {
            if(s[i] == c) {
                occ++;
            }
        }

        ans = occ + (occ*(occ-1))/2;
        return ans;
    }
};