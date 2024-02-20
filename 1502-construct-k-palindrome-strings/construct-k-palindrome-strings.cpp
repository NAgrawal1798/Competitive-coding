class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() == k) {
            return true;
        }
        if (s.size() < k) {
            return false;
        }
        map<char, int>mp;
        for(auto x: s) {
            mp[x]++;
        }
        int odd_count=0;
        for(auto x: mp) {
            if (x.second%2 != 0) {
                odd_count++;
            }
        }

        return odd_count <= k;
    }
};