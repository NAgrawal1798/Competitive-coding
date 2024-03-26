class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i=0; 
        int j=0;
        int n = s.size();
        int m = g.size();
        int count=0;
        while(i<n && j<m) {
            if(s[i] >= g[j]) {
                i++;
                j++;
                count++;
            } else {
                i++;
            }
        }

        return count;
    }
};