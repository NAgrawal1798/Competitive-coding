class Solution {
public:
    // Use dijstra algo
    int dp[26][26];
    long diskstra(unordered_map<char, vector<pair<char, long>>>&mp, char s, char t) {
        if (dp[s-'a'][t - 'a'] != -1) {
            return dp[s-'a'][t-'a'];
        }
        using p = pair<long, char>;
        // use priority queue --- min heap
        priority_queue<p, vector<p>, greater<p>>pq;
        pq.push({0, s});
        vector<int> distance(26, INT_MAX);
        distance[s-'a'] = 0;
        while(pq.size()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if(u==t) {
                return dp[s-'a'][t-'a'] = distance[t-'a'];
            }
            for(auto [v, weight]: mp[u]) {
                if(weight + cost < distance[v-'a']) {
                    distance[v-'a'] = weight + cost;
                    pq.push({distance[v-'a'], v});
                }
            }
        }



        // If not able to found it
        return -1;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        int size = cost.size();
        unordered_map<char, vector<pair<char, long>>>mp;
        memset(dp, -1, sizeof(dp));
        long ans = 0;
        for(int i=0; i<size; i++) {
            mp[original[i]].push_back({changed[i], cost[i]});
        }
        for(int i=0; i<n; i++) {
            if(source[i] != target[i]) {
                long x = diskstra(mp, source[i], target[i]);
                if (x==-1) {
                    return -1;
                }
                ans += x;
            }
        }

        return ans;
    }
};