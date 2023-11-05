class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int size = friendships.size();
        vector<pair<int, int>> p;
        unordered_map<int, int> mp;

        // Iterate through the friendships and check if there's a common language.
        for (int i = 0; i < size; i++) {
            vector<int> friends = friendships[i];
            int first = friends[0];
            int second = friends[1];

            vector<int> first_friend = languages[first - 1];
            vector<int> second_friend = languages[second - 1];

            int flag = 0;
            for (int j = 0; j < first_friend.size(); j++) {
                for (int k = 0; k < second_friend.size(); k++) {
                    if (first_friend[j] == second_friend[k]) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 0) {
                p.push_back({first, second});
                mp[first]++;
                mp[second]++;
            }
        }

        // Sort the pair vector based on the frequency of occurrences.
        sort(p.begin(), p.end(), [&](pair<int, int> a, pair<int, int> b) {
            return mp[a.first] + mp[a.second] > mp[b.first] + mp[b.second];
        });

        int minTeachings = INT_MAX;

        for (int lang = 1; lang <= n; lang++) {
            unordered_set<int> needTeach;
            for (int i = 0; i < p.size(); i++) {
                if (find(languages[p[i].first - 1].begin(), languages[p[i].first - 1].end(), lang) == languages[p[i].first - 1].end()) {
                    needTeach.insert(p[i].first);
                }
                if (find(languages[p[i].second - 1].begin(), languages[p[i].second - 1].end(), lang) == languages[p[i].second - 1].end()) {
                    needTeach.insert(p[i].second);
                }
            }
            minTeachings = min(minTeachings, static_cast<int>(needTeach.size()));
        }

        return minTeachings;
    }
};
