class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string>st;

        for (int i=0; i<words.size(); i++) {
            st.insert(words[i]);
        }

        for(auto word: words) {
            for(int k=1; k<word.length(); k++) {
                st.erase(word.substr(k));
            }

        }

        int ans = 0;
        for(auto word: st) {
            ans += word.length() + 1;
        }
        return ans;
    }
};