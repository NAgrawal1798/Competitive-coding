class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int i=1;
        int n = word.size();

        int cnt = 1;
        while(i<n) {
            if((word[i] != word[i-1]) || cnt == 9) {
                ans += to_string(cnt);
                ans += word[i-1];
                cnt = 0;
            }
            i++;
            cnt++;
        }

        ans += to_string(cnt);
        ans += word[i-1];

        return ans;
    }
};