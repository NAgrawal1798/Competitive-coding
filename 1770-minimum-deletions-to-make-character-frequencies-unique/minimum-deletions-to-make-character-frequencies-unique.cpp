class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int>mp;
        int length = s.length();

        for (int i=0; i<length; i++) {
            mp[s[i]]++;
        }

        priority_queue<int>q;

        for (auto i:mp) {
            if (i.second > 0) {
                q.push(i.second);
            }
        }

        int delete_n = 0;

        while(q.size() > 1) {
            int value = q.top();
            q.pop();

            if (value == q.top()) {
                if (value - 1 > 0) {
                    q.push(value - 1);
                }
                delete_n++;
            }
        }

        return delete_n;
    }
};