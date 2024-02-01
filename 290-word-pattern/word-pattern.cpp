class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string>mp;
        set<char>s1;
        set<string>s2;
        int j=0;
        int k=0;
        int count=0;
        for(int i=0;i<s.size();i++)
        if(s[i]==' ')
        count++;
        for(int i=0; i<pattern.size(); i++) {
            while(j<s.size() && s[j] != ' ') {
                j++;
            }
            if(j==s.size() && i!= pattern.size()-1) {
                return false;
            }
            string temp = s.substr(k,j-k);
            k=j+1;
            j=k;
            if(mp.find(pattern[i]) == mp.end() && s1.count(pattern[i]) == 0 && s2.count(temp) == 0) {
                mp[pattern[i]] = temp;
            } else if(mp.find(pattern[i]) == mp.end() && s2.count(temp) > 0) {
                return false;
            } else {
                if(temp != mp[pattern[i]]) {
                    return false;
                }
            }
            s1.insert(pattern[i]);
            s2.insert(temp);
        }
        if(++count!=pattern.size())
        return false;
        return true;
    }
};