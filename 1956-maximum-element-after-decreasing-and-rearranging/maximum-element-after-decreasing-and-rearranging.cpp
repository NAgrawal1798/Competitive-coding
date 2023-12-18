class Solution {
public:
    // arr
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int ans = 1;
        int n = arr.size();
        arr[0]= 1;

        for (int i=0; i<n-1; i++) {
            int diff = arr[i+1] - arr[i];
            if (diff > 1) {
                arr[i+1] = arr[i] + 1;
            }
            ans = max(ans, arr[i+1]);
        }

        return ans;
    }
};