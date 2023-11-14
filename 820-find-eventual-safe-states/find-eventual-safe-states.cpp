class Solution {
public:
    // Steps:
    // 1. Reverse the graph - complete
    // 2. Calculate rank of all nodes
    // 3. INsert the nodes that has 0 rank into queue
    // 4. INsert direct child of that node in the ans
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
                int n = graph.size();

        vector<vector<int>>adj(n);
        vector<int>dis(n, 0);
        for (int i=0; i<n; i++) {
            vector<int>adjNode = graph[i];
            for (int j=0; j<adjNode.size(); j++) {
                adj[adjNode[j]].push_back(i);
                dis[i]++;
            }
        }

        queue<int>q;

        for (int i=0; i<n; i++) {
           if (dis[i] == 0) {
               q.push(i);
           }
        }

        vector<int>ans;
        while(!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for (auto x : adj[node]) {
                dis[x]--;
                if (dis[x] == 0) {
                    q.push(x);
                }
            }
        }
        sort(ans.begin(), ans.end());


        return ans;
        
    }
};