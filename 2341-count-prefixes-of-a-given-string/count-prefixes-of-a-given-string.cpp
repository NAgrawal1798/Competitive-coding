class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        // solve it using a naive approach
        int count=0;
        for(int i=0; i<words.size(); i++) {
            string w = words[i];
            bool isSuffix = true;
            for (int j=0; j<w.size(); j++) {
                if(s[j] != w[j]) {
                    isSuffix = false;
                }
            }
            if(isSuffix) {
                count++;
            }
        }

        return count;
    }
};