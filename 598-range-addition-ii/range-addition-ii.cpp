class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {

        int minix = INT_MAX;
        int miniy = INT_MAX;
        for (int i=0; i<ops.size(); i++) {
            if (ops[i][0] < minix) {
                cout<<"Dfgdfg"<<endl;
                minix = ops[i][0];
            }
            if (ops[i][1] < miniy) {
                cout<<"sdfsdf"<<endl;
                miniy = ops[i][1];
            }
        }

        if (minix == INT_MAX) {
            return m*n;
        }
        return minix * miniy;
    }
};