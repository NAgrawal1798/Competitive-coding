class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for(int i=0; i<n; i++) {
            int index = i;
            int j=0;
            while( j<m && haystack[index] == needle[j]) {
                j++;
                index++;
            }
            if(j==m) {
                return i;
            }
        }

        return -1;
    }
};