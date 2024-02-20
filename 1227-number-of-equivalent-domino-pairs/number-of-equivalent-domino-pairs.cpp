class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>, int>mp;

        int n = dominoes.size();
        for(int i=0; i<n; i++) {
            int x = dominoes[i][0];
            int y = dominoes[i][1];
            if (x >y) {
                mp[{x,y}]++;
            } else {
                mp[{y,x}]++;
            }
        }

        int ans = 0;
        for(auto it: mp) {
            int x = it.second;
            ans += (x*(x-1))/2;
            // ans += it.second;
        }

        return ans;
    }
};