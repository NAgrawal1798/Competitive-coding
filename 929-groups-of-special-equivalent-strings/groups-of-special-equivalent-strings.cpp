class Solution {
public:
    int numSpecialEquivGroups(vector<string>& w) {
        unordered_set<string>s;

        for (int i=0; i<w.size(); i++) {
            string even= "";
            string odd = "";

            for (int j=0; j<w[i].size(); j++) {
                if(j%2 ==0) {
                    even += w[i][j];
                } else {
                    odd += w[i][j];
                }
            }

            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            s.insert(even+odd);
        }

        return s.size();
    }
};