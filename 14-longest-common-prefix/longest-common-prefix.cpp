class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int mini = INT_MAX;
        int n = strs.size();
        for(auto s: strs) {
            int size = s.size();
            mini = min(size, mini);
        }

        int i=0;
        while(i<mini) {
            char current = strs[0][i];
            for(int j=1; j<n; j++) {
                char s = strs[j][i];
                if(s != current) {
                    return ans;
                }
            }
            ans += current;
            i++;
        }

        return ans;
    }
};