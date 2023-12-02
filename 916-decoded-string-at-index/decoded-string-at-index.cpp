class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long n = s.size();
        long long  totalSize = 0;
        for (long long i=0; i<n; i++) {
            if ((s[i] - '0') >= 2 && (s[i] - '0') <= 9) {
                totalSize= totalSize* (s[i]- '0');
            } else {
                totalSize++;
            }
        }

        // Decode the string in the reverse order
        for (int i= s.size() - 1; i>=0; i--) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                int digit = currentChar - '0';
                totalSize /= digit;
                k %= totalSize;
            } else {
                if (k==0 || k == totalSize) {
                    return string(1, currentChar);
                }
                totalSize--;
            }
        }
        return "";
    }
};