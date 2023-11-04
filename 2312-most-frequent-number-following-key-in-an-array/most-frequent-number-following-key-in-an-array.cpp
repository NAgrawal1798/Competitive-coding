class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int>mp;

        int size = nums.size();

        for (int i=0; i<size-1; i++) {
            if(nums[i] == key) {
                mp[nums[i+1]]++;
            }
        }

        int count =INT_MIN;
        int ans;

        for (auto it: mp) {
            if (count < it.second) {
                count = it.second;
                ans = it.first;
            }
        }

        return ans;
    }
};