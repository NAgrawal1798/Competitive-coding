class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        // kind of a map question
        // map will store the count of words

        map<string,int>mp;
        for(int i=0; i<messages.size(); i++) {
            string message = messages[i];
            string sender = senders[i];

            int count=0;
            for(int j=0; j<message.size(); j++) {
                if (message[j] == ' ') {
                    count++;
                }
            }
            count++;

            if (mp.find(sender) == mp.end()) {
                mp[sender] = count;
            } else {
                mp[sender] += count;
            }
        }

        string ans="";
        int c = 0;
        for(auto it: mp) {
            if(it.second == c) {
                ans = max(ans, it.first);
            }
            if (it.second > c) {
                ans = it.first;
                c = it.second;
            }
        }

        return ans;
    }
};