class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        set<string>s;
        int ans = 0;

        for(int i=0; i<words.size(); i++) {
            string temp = words[i];

            if(s.count(temp) > 0) {
                ans++;
            }

            s.insert(temp);
            reverse(temp.begin(), temp.end());
            s.insert(temp);
        }

        return ans;

    }
};