class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.size();
        int count= 0;
        int flag = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == 'L') {
                flag--;
            } else {
                flag++;
            }

            if(flag == 0) {
                count++;
            }
        }

        return count;
    }
};