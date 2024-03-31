class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<int>());
        
        int sum = 0;
        int n = apple.size();
        for(int i=0; i<n; i++) {
            sum += apple[i];
        }

        int m = capacity.size();
        for(int j=0; j<m; j++) {
            sum -= capacity[j];
            if(sum <= 0) {
                return j+1;
            }
        }

        return 0;
    }
};