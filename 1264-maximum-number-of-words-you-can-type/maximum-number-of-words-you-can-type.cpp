class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char>st;

        for(int i=0; i<brokenLetters.size(); i++) {
            st.insert(brokenLetters[i]);
        }

        int count=0;

        string t = "";
        vector<string>s;
        for(int i=0; i<text.size() ;i++) {
            if(text[i] != ' ') {
                t += text[i];
            } else {
                s.push_back(t);
                t = "";
            }
        }

        if(t != " ") {
            s.push_back(t);
        }



        for (int i=0; i<s.size(); i++) {
            string temp = s[i];
            cout<<temp<<endl;
            for(int j=0; j<temp.size(); j++) {
                if(st.count(temp[j]) > 0) {
                    count++;
                    break;
                }
            }
        }

        return s.size() - count;
    }
};