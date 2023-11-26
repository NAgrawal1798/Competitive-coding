class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();

        vector<vector<int>>adj(n);
        vector<int>indegree(n);
        vector<int>ans(n);



        for (int i=0; i<richer.size(); i++) {
            int u = richer[i][0];
            int v = richer[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int>q;
        for (int i=0; i<n; i++) {
            ans[i] = i;
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it: adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
                if (quiet[ans[it]] > quiet[ans[node]]) {
                    ans[it] = ans[node];
                }
            }
        }

        return ans;

    }
};