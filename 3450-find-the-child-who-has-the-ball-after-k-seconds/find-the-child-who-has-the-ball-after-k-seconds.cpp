class Solution {
public:
    int numberOfChild(int n, int k) {
        n--;
        int d = k/n;
        int r = k%n;

        cout<<d<<" "<<r<<endl;

        if(d%2 == 0) {
            return r;
        } return n-r;
    }
};