class Solution {
public:
    int helper(int a, int b) {
        int c=0;
        int l=1;
        int f=0;

        while(a>0 || b>0) {
            if (f==0) {
                if (a>=l) {
                    a=a-l;
                } else {
                    break;
                }
            } else {
                if (b>=l) {
                    b=b-l;
                } else {
                    break;
                }
            }
            c++;
            l++;
            f = !f;
        }
        return c;
    }
    int maxHeightOfTriangle(int red, int blue) {
        int k1 = helper(red, blue);
        int k2 = helper(blue, red);

        return max(k1, k2);
    }
};