class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char>s;

        for (int i=0; i<allowed.length(); i++) {
            s.insert(allowed[i]);
        }
        int ans = 0;

        for(int i=0; i<words.size(); i++) {
            string temp = words[i];
            int flag=1;
            for (int j=0; j<temp.length(); j++) {
                if (s.count(temp[j]) == 0) {
                    flag=0;
                }
            }
            if (flag) {
                ans++;
            }
        }

        return ans;
    }
};