class Solution {
public:
    bool helper(string s, set<string>&present, map<string, bool>&mp) {
        

        if (present.count(s)) {
            return true;
        }
        if (mp.find(s) != mp.end()) {
            return mp[s];
        }

        for (int i=1; i<s.length(); i++) {
            string left = s.substr(0,i);
            if (present.count(left) && helper(s.substr(i), present, mp)) {
                mp[left] = true;
                return true;
            }
        }

        return mp[s] = false;


    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>present;

        for (int i=0;i<wordDict.size(); i++) {
            present.insert(wordDict[i]);
        }

        
        map<string,bool>mp;
        return helper(s,present, mp);
    }
};