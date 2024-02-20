class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int mini = INT_MAX;
        for(int i=1; i<n; i++) {
            mini = min(mini, arr[i] - arr[i-1]);
        }

        vector<vector<int>>ans;
        for (int i=1; i<n; i++) {
            vector<int>temp;
            if (mini == (arr[i] - arr[i-1])) {
                temp.push_back(arr[i-1]);
                temp.push_back(arr[i]);
                ans.push_back(temp);
            }
        }

        return ans;
    }
};