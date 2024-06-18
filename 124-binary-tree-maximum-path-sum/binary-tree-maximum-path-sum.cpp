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
    int helper(TreeNode* root,  int& ans) {
        if (root == NULL) {
            return 0;
        }

        int leftMax = max(0, helper(root->left, ans));
        int rightMax = max(0, helper(root->right, ans));

        ans = max(ans, leftMax + rightMax + root->val);

        return root->val + max(leftMax, rightMax);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};