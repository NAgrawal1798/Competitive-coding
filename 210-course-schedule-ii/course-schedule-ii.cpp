class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;

        vector<int>indegree(numCourses, 0);
        vector<vector<int>>adj(numCourses);
        for (int i=0; i<prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            indegree[u]++;
            adj[v].push_back(u);
        }

        queue<int>q;

        for (int i=0; i<numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }

        if (ans.size() != numCourses) {
            return vector<int>{};
        }

        return ans;
    }
};