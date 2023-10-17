class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size(); // Assuming all votes have the same length
        int m = votes[0].size();
        vector<vector<int>> v(26, vector<int>(m+1, 0)); // Assuming there are 26 teams (A-Z)
        
        for (auto i = 0; i < 26; i++) {
    		v[i][m] = -(int('A') + i);
    	}

        for (int i=0; i<n; i++) {
            for (int j=0; j<m;j++) {
                v[votes[i][j] - 'A'][j]++;
            }
        }
    	string ans = "";

        sort(v.begin(), v.end(), greater<>());
    	for (auto i = 0; i < m; i++) {
    		ans += char(-v[i][m]);
    	}
    	return ans;
    }
};
