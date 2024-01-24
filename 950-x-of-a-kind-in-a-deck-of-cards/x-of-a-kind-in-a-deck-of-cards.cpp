class Solution {
public:

    int gcd(int x, int y) {
        if(x==0) {
            return y;
        }
        return gcd(y%x, x);
    }


    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int>count(10001,0);

        for (auto& i: deck) {
            count[i]++;
        }

        int g=-1;
        for(int i=0; i<10001; i++) {
            if(count[i] > 0) {
                if(g == -1) {
                    g = count[i];
                } else {
                    g = gcd(g, count[i]);
                }
            }
        }

        return g>=2;


    }
};