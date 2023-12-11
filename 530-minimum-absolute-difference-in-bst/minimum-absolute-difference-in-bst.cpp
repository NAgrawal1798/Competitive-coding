/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, vector<int>&ans) {
        if (root == NULL) {
            return;
        }
        ans.push_back(root->val);
        helper(root->left, ans);
        helper(root->right, ans);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>ans;
        helper(root, ans);
        sort(ans.begin(), ans.end());
        int mini = INT_MAX;
        int n = ans.size();
        for (int i=1; i<n; i++) {
            mini = min(mini, ans[i] - ans[i-1]);
        }
        return mini;
    }
};