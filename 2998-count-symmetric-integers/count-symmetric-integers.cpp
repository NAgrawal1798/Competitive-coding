class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i=low; i<=high; i++) {
            string s = to_string(i);
            if(s.size() % 2) {
                continue;
            }
            int half = s.size()/2;
            int left_half = 0;
            int right_half = 0;
            for(int j=0; j<half; j++) {
                left_half += s[j] - '0';
            }
            for(int k=half; k<s.size(); k++) {
                right_half += s[k] - '0';
            }
            if(left_half == right_half) {
                ans++;
            }
        }
        return ans;
    }
};