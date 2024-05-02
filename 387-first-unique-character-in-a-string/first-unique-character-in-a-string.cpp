class Solution {
public:
    int firstUniqChar(string s) {
        map<char, vector<int>>mp;
        for(int i=0; i<s.size(); i++) {
            mp[s[i]].push_back(i);
        }

        vector<int>indexes;
        for(auto it: mp) {
            if(it.second.size() == 1) {
                indexes.push_back(it.second[0]);
            }
        }
        if (indexes.size() == 0) {
            return -1;
        }
        sort(indexes.begin(), indexes.end());
        return indexes[0];
    }
};