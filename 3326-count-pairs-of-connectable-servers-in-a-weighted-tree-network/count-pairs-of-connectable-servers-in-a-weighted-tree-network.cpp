class Solution {
public:
    int dfs(int root, int par, int dist, vector<vector<pair<int, int>>>& graph, int singleSpeed) {
        int count = (dist% singleSpeed) ? 0 : 1;
        for(auto [n, w]: graph[root]) {
            if(n!= par) {
                count += dfs(n, root, dist + w , graph, singleSpeed);
            }
        }

        return count;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        // create graph from the edges
        vector<vector<pair<int,int>>> graph(edges.size() + 1);
        for(auto e: edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        vector<int>ans;
        // iterate over 0 to n and consider each node as the root node
        for(int i=0; i<=edges.size(); i++) {
            int nodeCount = 0;
            int res = 0;
            for(auto [n, w] : graph[i]) {
                int t = dfs(n , i , w, graph, signalSpeed);
                res += nodeCount*t;
                nodeCount += t;
            }
            // keep accumulating answer by multiplying the current sub tree valid node count with the previously seen node count
            ans.push_back(res);
        }
        return ans;
    }
};