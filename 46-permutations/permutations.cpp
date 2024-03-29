class Solution {
public:
    // backtracking
    // as all elements are unique
    void helper(vector<int>& nums, vector<vector<int>>&ans, vector<int>&temp, set<int>&s) {
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
        }
        for(int i = 0; i<nums.size(); i++) {
            // check if the element is already exist
            // write code it here 
            if(s.count(nums[i]) > 0) {
                continue;
            }
            s.insert(nums[i]);
            temp.push_back(nums[i]);
            helper(nums, ans, temp, s);
            int num = temp[temp.size() - 1];
            temp.pop_back();
            s.erase(num);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int i = 0;
        vector<int>temp;
        set<int>s;
        helper(nums, ans, temp, s);
        return ans;
    }
};