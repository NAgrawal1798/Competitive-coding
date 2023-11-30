class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();

        for(int i=0;i<n; i++) {
            shifts[i] = shifts[i]%26;
        }
        // cout<<shifts[0]<<" "<<endl;

        vector<int>suffix(n,0);
        suffix[n-1] = shifts[n-1];
        for (int i = n-2; i>=0; i--) {
            suffix[i] = shifts[i] + suffix[i+1];
        }

        for(int i=0;i<n; i++) {
            suffix[i] = suffix[i]%26;
            cout<<suffix[i]<<endl;
        }

        string ans = "";

        for (int i=0; i<n; i++) {
            if (('z' - s[i]) >= suffix[i]) {
                ans  += s[i] + suffix[i];   
            } else {
                int realshift = suffix[i] - ('z' - s[i]) - 1;
                cout<<realshift<<endl;
                ans += 'a' + realshift;
            }
        }

        return ans;
    }
};