class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int>cnt(26);
        for(char c: word) {
            cnt[c - 'a']++;
        }

        sort(cnt.begin(), cnt.end());
        int ans = 1e9;
        int startEle = 0;
        for(int i=0; i<26; i++) {
            int currDel = startEle;
            int topLimit = cnt[i] + k;
            for(int j=i+1; j< 26; j++) {
                if(topLimit < cnt[j]) {
                    currDel += cnt[j] - topLimit;
                }
            }

            ans = min(ans, currDel);
            startEle += cnt[i];
        }

        return ans;
    }
};