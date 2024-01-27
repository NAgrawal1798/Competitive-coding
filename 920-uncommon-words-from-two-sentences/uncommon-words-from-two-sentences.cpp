class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int>mp;

        for(int i=0; i<s1.length(); i++) {
            int j=i;
            string temp = "";
            while(j<s1.length()) {
                if(s1[j] == ' ') {
                    break;
                } else {
                    temp += s1[j];
                }
                j++;
            }
            mp[temp]++;
            i=j;
        }
        for(int i=0; i<s2.length(); i++) {
            int j=i;
            string temp = "";
            while(j<s2.length()) {
                if(s2[j] == ' ') {
                    break;
                } else {
                    temp += s2[j];
                }
                j++;
            }
            mp[temp]++;
            i=j;
        }
        vector<string>ans;
        for(auto it: mp) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};