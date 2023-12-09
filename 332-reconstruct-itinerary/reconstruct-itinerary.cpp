class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<string>> mp;

        // Build the adjacency list
        for (const auto& ticket : tickets) {
            string start = ticket[0];
            string end = ticket[1];
            mp[start].push_back(end);
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
                string next = mp[current].front(); // Access the first element
                dfs.push(next);
                mp[current].erase(mp[current].begin()); // Erase the used ticket
            }
        }

        reverse(itinerary.begin(), itinerary.end()); // Reverse to get correct order
        return itinerary;
    }
};
