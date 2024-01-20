class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int maxi = nums[nums.size() - 1];
        int mini = nums[0];

        int newMaxi = maxi - k;
        int newMini = mini + k;


        if (newMaxi > newMini) {
            return newMaxi - newMini;
        }
        return 0;
    }
};