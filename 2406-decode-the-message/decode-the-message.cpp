class Solution {
public:
    string decodeMessage(string key, string message) {
        // use map
        vector<int>v(26,-1);

        int counter=0;
        for(int i=0; i<key.size(); i++) {
            if(key[i] != ' ') {
                int s = key[i] - 'a';
                if(v[s] == -1) {
                    v[s] = counter;
                    counter++;
                }
            }
        }

        string ans = "";
        for(int i=0; i<message.size(); i++) {
            if (message[i] != ' ') {
                int index = message[i] - 'a';
                char asciiCode = v[index] + 97;
                ans += static_cast<char>(asciiCode);
            } else {
                ans += " ";
            }
        }

        return ans;
    }
};