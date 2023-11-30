class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        set<int>s;
        int n = arr.size();

        for (int i=0; i<n; i++) {
            s.insert(arr[i]);
        }
        int ans = 0;

        for (int i=0; i<n; i++) {
            for (int j=i+1; j< n-1; j++) {
                int x = arr[i];
                int y = arr[j];
                int l=2;
                while(s.count(x + y)) {
                    int z = x + y;
                    x=y;
                    y=z;
                    l++;
                }
                ans = max(ans, l);
            }
        }

        return ans>2?ans:0;
    }
};