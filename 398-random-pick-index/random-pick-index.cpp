class Solution {
public:
    map<int, vector<int>>mp;
    Solution(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int>positions = mp[target];
        int size = positions.size();
        int random = rand()%size;
        return positions[random];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */