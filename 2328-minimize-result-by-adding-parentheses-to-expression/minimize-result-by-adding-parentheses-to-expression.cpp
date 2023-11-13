class Solution {
public:
    string minimizeResult(string expression) {
        int i=0;
        int j=0;

        int pos = expression.find('+');
        string before = expression.substr(0, pos);

        string after = expression.substr(pos + 1); 

        string ans="";
        int count=INT_MAX;
        int n = before.length();
        int m = after.length();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int left;
                if (i==0) {
                    left = 1;
                } else {
                    left = stoi(before.substr(0,i));
                }
                int middle = stoi(before.substr(i, n-i)) + stoi(after.substr(0, j+1));

                int right;
                if (j==m-1) {
                    right=1;
                } else {
                    right = stoi(after.substr(j+1, m-j-1));
                }

                if (left*middle*right < count) {
                    count = left*middle*right;
                    ans = before.substr(0,i) + "(" + before.substr(i, n-i) + "+" + after.substr(0, j+1) + ")" + after.substr(j+1, m-j-1);
                }
            }
        }

        // cout<<before<<" "<<after<<endl;
        return ans;
    }
};