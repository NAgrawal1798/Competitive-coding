class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        sort(s1.begin(), s1.end());

        int i=0;
        while((i + n1 - 1)<n2) {
            string s = s2.substr(i, n1);
            sort(s.begin(), s.end());
            if(s == s1) {
                return true;
            }
            i++;
        }

        return false;
    }
};