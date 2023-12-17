class Solution {
public:

    vector<int>a[100002];
    void helper(vector<int>&ans, vector<int>& parents, int start) {
        ans[start] = 1;
        for (auto i: a[start]) {
            if (i == parents[start]) {
                continue;
            }
            helper(ans, parents, i);
            ans[start] += ans[i];
        }
    }
    int countHighestScoreNodes(vector<int>& parents) {
        for (int i=0; i<parents.size(); i++){
            a[i].clear();
        }
        for (int i=1; i<parents.size(); i++) {
            a[parents[i]].push_back(i);
            a[i].push_back(parents[i]);
        }
        int start = 0;
        vector<int>ans(parents.size(),0);
        helper(ans, parents, start);
        vector<vector<int>>child(parents.size());
        for (int i=0; i<parents.size(); i++) {
            if (parents[i] != -1) {
                child[parents[i]].push_back(i);
            }
        }

        map<long long, int>mp;
        for (int i=0; i<parents.size(); i++) {
            long long child1=1;
            long long child2=1;
                if (child[i].size() >=1) {
                    child1 = ans[child[i][0]];
                    child2 = child[i].size() > 1 ? ans[child[i][1]]:1;
                }
            mp[child1*child2*max(1LL, (long long )(parents.size() - ans[i]))]++;
        }

        long long cnt=-1;
        for (auto [x,y] : mp) {
            cnt = max(cnt, x);
        }
        return mp[cnt];
    }
};