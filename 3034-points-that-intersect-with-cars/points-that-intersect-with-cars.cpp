class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int>ans(101, 0);
        for(int i=0; i<n; i++) {
          int start = nums[i][0];
          int end = nums[i][1];
          for(int j=start; j<=end; j++) {
            ans[j] = 1;
          }
        }

        int cnt = 0;
        for(int i=0; i<101; i++) {
            if(ans[i] == 1) {
                cnt++;
            }
        }

        return cnt;

    }
};