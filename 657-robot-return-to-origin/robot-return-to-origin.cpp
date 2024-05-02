class Solution {
public:
    bool judgeCircle(string moves) {
        int cntU = 0;
        int cntL = 0;
        for(auto s: moves) {
            if(s == 'U') {
                cntU++;
            } else if (s == 'D') {
                cntU--;
            } else if (s == 'L') {
                cntL++;
            } else {
                cntL--;
            }
        }

        if (cntL == 0 && cntU == 0) {
            return true;
        }
        return false;
    }
};