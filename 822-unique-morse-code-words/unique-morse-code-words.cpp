class Solution {
public:
    vector<string>codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string>s;

        for (int i=0; i<words.size(); i++) {
            string code = "";
            for (char c: words[i]) {
                code += codes[c - 'a'];
            }
            s.insert(code);
        }

        return s.size();
    }
};