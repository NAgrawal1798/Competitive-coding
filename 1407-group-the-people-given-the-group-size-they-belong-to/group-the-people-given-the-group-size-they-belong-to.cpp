class Solution {
public:
    // Approaches i am thinking about
    // 1. Use some kind of map to store the values
    // map[group_size] = vector<int>
    // mp<3> = {0,1,2,3,4}
    // mp<1> = {5}
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>>mp;

        for (int i=0; i<groupSizes.size(); i++) {
            if (mp.find(groupSizes[i]) == mp.end()) {
                vector<int>v;
                v.push_back(i);
                 mp[groupSizes[i]] = v;
            } else {
                vector<int>v = mp[groupSizes[i]];
                v.push_back(i);
                mp[groupSizes[i]] = v;
            }
        }

        vector<vector<int>>ans;

        for (auto it: mp) {
            vector<int>v;
            for (auto it1 : mp[it.first]) {
               v.push_back(it1);
               if (v.size() == it.first) {
                   ans.push_back(v);
                   v.clear();
               }
            }
        }

        return ans;
    }
};