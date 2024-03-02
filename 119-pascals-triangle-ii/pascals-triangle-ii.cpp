class Solution {
public:
    vector<int> getRow(int n) {
        // Use 2 rows
    vector<int> temp;
    vector<int> res;

    if(n==0) {
        return {1};
    }

    res = {1,1};

    for (int i = 2; i <= n; i++) {
        temp.resize(i+1, 0);
        temp[0] = 1;
        temp[temp.size()-1] = 1;
        for (int j = 1; j < temp.size()-1; j++) {
            temp[j] = res[j - 1] + res[j];
        }
        res = temp;
    }

    return res;
    }
};