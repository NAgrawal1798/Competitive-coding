class Solution {
public:

    string getMinString(string a , string b) { //compare two string with min size or if equal then return lexicographically smaller string 
        if(a.size() < b.size()) {
            return a;
        } else if(a.size() > b.size()) {
            return b;
        } else {
            return a<b?a:b;
        }
    }

    string addTwoStrings(string &a, string &b) { // a= abc, b= c
        if(b.find(a) != string::npos) {
            return b;
        }
        for(int i=0; i<a.size(); i++) {
            string t1 = a.substr(i);
            string t2 = b.substr(0, t1.size());
            if(t1 == t2) {
                return a + b.substr(t1.size());
            }
        }

        return a+b;
    }
    string solve(string &a, string &b, string &c) {
        string t1 = addTwoStrings(a, b);
        string t2 = addTwoStrings(b, a);

        string res1 = getMinString(addTwoStrings(t1, c), addTwoStrings(c, t1));
        string res2 = getMinString(addTwoStrings(t2, c), addTwoStrings(c, t2));

        return getMinString(res1, res2);

    }
    string minimumString(string a, string b, string c) {
        // try all possible opportunity
        // a, b and add c
        // b, a and add c

        // b,c  and add a
        // c,b  and add a

        // c,a and add b
        // a, c and add b

        // that's why it has only 3 strings
        string res = getMinString(solve(a,b,c), solve(b,c,a));
        return getMinString(res, solve(c,a,b));
    }
};