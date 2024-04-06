class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();

        if(n<2) {
            return 0;
        }

        int sum = nums[0] + nums[1];
        int ans = 1;


        for(int i=2; i<n; i+=2) {
            if(i+1 < n) {
                if(sum == (nums[i] + nums[i+1])) {
                    ans++;
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};