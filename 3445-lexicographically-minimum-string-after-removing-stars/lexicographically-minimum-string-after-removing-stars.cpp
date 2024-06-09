class Solution {
public:
    string clearStars(string s) {
        // stepwise step
        // 1. Find the smallest charcter in the left
        // 2. delete each occurence of that character and find make a smallest string
        // 3. repeat above 2 steps
        int n = s.size();
        vector<vector<int>>buckets(26);
        vector<int>removed(n, 0);

        for(int i=0; i<n; i++) {
            if(s[i] == '*') {
                removed[i] = 1;
                for(int j=0; j<26; j++) {
                    if(buckets[j].size()) {
                        removed[buckets[j].back()] = 1;
                        buckets[j].pop_back();
                        break;
                    }
                }
            } else {
                buckets[s[i] - 'a'].push_back(i);
            }
        }

        string ans;
        for(int i=0; i<n; i++) {
            if(!removed[i]) {
                ans += s[i];
            }
        }

        return ans;
    }
};