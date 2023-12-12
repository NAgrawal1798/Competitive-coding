class Solution {
public:
    // dp solution
    int jump(vector<int>& nums) {

        int n = nums.size();
        vector<int>jumps(n, INT_MAX);

        jumps[0] = 0;

        int i=0;
        while(i < n) {
            int num = nums[i];
            int k=1;

            while(k <= num && i+k < n) {
                if (jumps[i+k] > jumps[i] + 1) {
                    jumps[i+k] = jumps[i] + 1;
                }
                k++;
            }
            i++;
        }

        return jumps[n-1];
    }
};