class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> m(s.length()+1, false);
        m[0] = true;

        for(int i=0; i<s.length(); ++i) {
            if(m[i]==true) {
                for(auto word : wordDict) {
                    if(i+word.length()-1<n) {
                        if(word==s.substr(i, word.length())) {
                            m[i+word.length()] = true;
                        }
                    }
                }
            }
        }


        return m[s.length()];
    }
};