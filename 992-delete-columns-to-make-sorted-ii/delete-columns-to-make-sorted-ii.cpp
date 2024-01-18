class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        vector<string>vec(n, ""); // To store string in lexocographically order

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                vec[j] += strs[j][i]; //  Adding one character from each row
            }

            int var = 1;

            for (int j=1; j<n; j++) {
                if (vec[j] < vec[j-1]) {
                    var = -1;
                    break;
                }
            }

            if(var == -1) {
                for (int j=0; j<n; j++) {
                    vec[j].pop_back();
                }
            }
        }

        return m - vec[0].size();
    }
};