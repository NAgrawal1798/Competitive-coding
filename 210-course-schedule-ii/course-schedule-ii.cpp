class Solution {
public:
    // Make a graph
    // Appy dfs or bfs to count the nodes

    // void dfs(vector<vector<int>>& adj, stack<int>&s, int node, vector<int>&visited) {
    //     visited[node] = 1;

    //     for (auto it: adj[node]) {
    //         if (!visited[it]) {
    //             dfs(adj, s, it, visited);
    //         } 
    //     }

    //     s.push(node);
    // }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<int>indegree(numCourses, 0);
        queue<int>q;
        vector<vector<int>>adj(numCourses);

        for (int i=0;i<prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i=0;i<numCourses; i++) {
            for (auto it: adj[i]) {
                indegree[it]++;
            }
        }

        for (int i=0; i<numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for (auto it: adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        if (ans.size() == numCourses) {
            return ans;
        }

        return {};



        // for (int i=0; i<numCourses; i++) {
        //     if (!visited[i]) {
        //         dfs(adj, s, i, visited);
        //     }
        // }

        // while(!s.empty()) {
        //     ans.push_back(s.top());
        //     s.pop();
        // }
        return ans;
    }
};