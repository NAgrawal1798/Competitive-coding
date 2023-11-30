class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int>mp;

        int n = s.length();
        for (int i=0; i<n; i++) {
            mp[s[i]] = i;
        }

        int anchor = 0;
        vector<int>v;
        int j=0;

        for (int i=0;i<n;i++) {
            j = max(j, mp[s[i]]);

            if (i == j) {
                v.push_back(i - anchor + 1);
                anchor = i+1;
            }
        }

        return v;
    }
};