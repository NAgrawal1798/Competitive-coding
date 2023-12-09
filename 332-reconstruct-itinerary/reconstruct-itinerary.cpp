class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<pair<string, int>>> mp;

        // Build the adjacency list
        for (const auto& ticket : tickets) {
            string start = ticket[0];
            string end = ticket[1];
            mp[start].emplace_back(end, 0); // Use emplace_back instead of push_back
        }

        // Sort destinations in lexical order
        for (auto& entry : mp) {
            sort(entry.second.begin(), entry.second.end());
        }

        vector<string> itinerary;
        stack<string> dfs;

        dfs.push("JFK"); // Starting point

        while (!dfs.empty()) {
            string current = dfs.top();

            if (mp[current].empty()) {
                itinerary.push_back(current);
                dfs.pop();
            } else {
                auto next = mp[current].begin();
                dfs.push(next->first);
                next->second = 1; // Mark this ticket as used
                mp[current].erase(next); // Erase the used ticket
            }
        }

        reverse(itinerary.begin(), itinerary.end()); // Reverse to get correct order
        return itinerary;
    }
};
