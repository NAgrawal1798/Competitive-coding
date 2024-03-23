class Solution {
public:
    string largestPalindromic(string s) {
        vector<int> v(10);
        for (char c : s) {
            v[c - '0']++;
        }
        string ans;
        int single = -1;
        for (int i = 9; i >= 0; i--) {
            if(ans.empty() && i==0) {
                break;
            }
            while (v[i] > 1) {
                ans.push_back(i + '0');
                v[i] -= 2;
            }
            if (v[i] && single == -1) {
                single = i;
            }
        }
        string res = ans;
        reverse(res.begin(), res.end());
        if(ans.empty() && single == -1) {
            return "0";
        }
        if(single !=-1) {
            ans.push_back(single + '0');
        }
        ans += res;
        return ans;
    }
};