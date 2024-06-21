class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;

        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }

        vector<vector<int>>v(nums.size() + 1);

        for(auto it: mp) {
            v[it.second].push_back(it.first);
        }

        vector<int>ans;
        for(int i=v.size() - 1; i>=0; i--) {
            for(int j=0; j<v[i].size(); j++) {
                if (k > 0) {
                    ans.push_back(v[i][j]);
                    k--;
                }
            }
        }

        return ans;
    }
};