class Solution {
public:
    void helper(vector<int>& candidates, int target, int index, vector<vector<int>>&ans,
    vector<int>& temp) {
        // base case
        if(target < 0) {
            return;
        }
        if(target == 0) {
            ans.push_back(temp);
        }

        // backtracking
        for(int i=index; i<candidates.size(); i++) {
                temp.push_back(candidates[i]);
                helper(candidates, target - candidates[i], i, ans, temp);
                temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int i=0;
        helper(candidates, target, i, ans, temp);
        return ans;
    }
};