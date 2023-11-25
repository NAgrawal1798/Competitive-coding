class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& temp, int start) {
    if (target == 0) {
        ans.push_back(temp);
        return;
    }

    for (int i = start; i < candidates.size(); ++i) {
        // Skip duplicates to avoid redundant combinations
        if (i > start && candidates[i] == candidates[i - 1]) {
            continue;
        }

        if (candidates[i] <= target) {
            temp.push_back(candidates[i]);
            // Recursive call with the updated target and start index
            helper(candidates, target - candidates[i], ans, temp, i + 1);
            temp.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
    helper(candidates, target, ans, temp, 0);
    return ans;
}

};