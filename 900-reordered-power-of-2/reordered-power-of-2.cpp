class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string x = to_string(n);
        sort(x.begin(), x.end());
        for (int i=0; i<32; i++) {
            string temp = to_string(1<<i);
            sort(temp.begin(), temp.end());
            if (x==temp) {
                return true;
            }
        }
        return false;
    }
};