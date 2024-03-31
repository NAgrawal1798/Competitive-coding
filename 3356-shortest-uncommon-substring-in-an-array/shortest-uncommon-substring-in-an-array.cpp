class Solution {
public:

    static bool cmp(string a, string b) {
        if(a.size() < b.size()) {
            return true;
        }
        if(a.size() == b.size() && a< b) {
            return true;
        }
        return false;
    }
    vector<string> shortestSubstrings(vector<string>& arr) {
        // Though process
        // Use set to store the all possible substrings
        // use pair<substring, original str or index>

        // approch was correct but key take away is to store the subtstrings
        // in the vector of vector

        // approch was correct but some small things were missed

        map<string, int>mp;
        int n = arr.size();

        vector<string>ans(n , "");
        vector<vector<string>>substring(n);
        
        for(int i=0; i<n; i++) {
            string temp = arr[i];

            int m = temp.size();
            for(int j=0; j<m; j++) {
                for(int k=j; k<m; k++) {
                    string sub = temp.substr(j,k-j+1);
                    bool found = false;
                    for(auto str: substring[i]) {
                        if(str == sub) {
                            found = true;
                            break;
                        }
                    }
                    if(found) {
                        continue;
                    }
                    mp[sub]++;
                    substring[i].push_back(sub);
                }
            }

            sort(substring[i].begin(), substring[i].end(), cmp);
        }

        for(int i=0; i<n; i++) {
            for(auto it: substring[i]) {
                if(mp[it] == 1) {
                    ans[i] = it;
                    break;
                }
            }
        }

        return ans;
    }
};