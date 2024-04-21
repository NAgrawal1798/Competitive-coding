class Solution {
public:
    // dp solution
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>jumps(n+1000, INT_MAX);
        jumps[0] = 0;
        for(int i=0; i<n; i++) {
            int dist = nums[i];
            for (int j = 1; j <= dist && i + j < n; j++) {
                jumps[i + j] = min(jumps[i] + 1, jumps[i + j]);
            }
        }

        return jumps[n-1];
    }
};