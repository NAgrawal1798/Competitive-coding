class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // use of O(n) space complexity
        // It will be always in the sorted form
        map<int, int>mp;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (mp.find(nums[i]) != mp.end()) {
                int x = mp[nums[i]];
                if (abs(x-i) <= k) {
                    return true;
                }
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};