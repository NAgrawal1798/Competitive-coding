class Solution {
public:
    void helper(int n, string temp, string tiles, unordered_set<string> &st, vector<bool> & vis) {
        st.insert(temp);

        for(int i=0; i<n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                helper(n, temp + tiles[i], tiles, st, vis);
                vis[i] = false;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        unordered_set<string>st;
        vector<bool> vis(n, false);
        helper(n, "", tiles, st, vis);
        return st.size() -1;
    }
};