class Solution {
public:
    vector<string>alpha = {
        ".-","-...","-.-.","-..",".","..-.","--.",
        "....","..",".---","-.-",".-..","--","-.",
        "---",".--.","--.-",".-.","...","-","..-",
        "...-",".--","-..-","-.--","--.."
    };
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string>st;
        for(auto s: words) {
            string encoded = "";
            for(int i=0; i<s.size(); i++) {
                encoded += alpha[s[i] - 'a'];
            }
            st.insert(encoded);
        }

        return st.size();
    }
};