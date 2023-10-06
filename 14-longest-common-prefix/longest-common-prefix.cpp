class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        int smallestLength = INT_MAX;

        for (int i=0; i<strs.size(); i++) {
            if (smallestLength > strs[i].size()) {
                smallestLength = strs[i].size();
            }
        }

        int i=0;

        while(i<smallestLength) {
            char c = strs[0][i];
            bool allTrue = true;
            for (int j=0; j< strs.size(); j++) {
                if (strs[j][i] != c) {
                    allTrue = false;
                    break;
                }
            }
            if (!allTrue) {
                break;
            }
            ans += c;
            i++;
        }

        return ans;
    }
};