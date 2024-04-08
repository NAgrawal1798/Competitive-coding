class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // find the strictly increasing

        int ans = 0;
        int n = nums.size();
        int start = 0;
        int end = 0;
        for(int i=1; i<n; i++) {
            if(nums[i-1] < nums[i]) {
                end = i;
            } else {
                ans = max(end - start+1, ans);
                start = i;
                end = i;
            }
        }
         ans = std::max(end - start + 1, ans);


        // find the strictly decreasing
        start = n-1;
        end = n-1;
        for(int i= n-2; i>=0 ;i--) {
            if(nums[i+1] < nums[i]) {
                end = i;
            } else {
                ans = max(start - end +1, ans);
                start = i;
                end = i;
            }
        }

        ans = std::max(start - end + 1, ans);

        return ans;
    }
};