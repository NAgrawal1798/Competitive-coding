class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i=0;
        int n = chalk.size();
        long long int totalSize = 0;

        for (int i=0; i<n; i++) {
            totalSize +=chalk[i];
        }
        int newK = k%totalSize;
        cout<<newK<<endl;
        for (int i=0; i<n; i++) {
            if ((newK - chalk[i]) < 0) {
                return i;
            }
            newK -=chalk[i];
        }
        return 0;
    }
};