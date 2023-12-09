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
    int dfs(TreeNode* root, int& maxPath) {
        if (root == NULL) {
            return 0;
        }

        int lmax = max(dfs(root->left, maxPath), 0);
        int rmax = max(dfs(root->right, maxPath), 0);

        maxPath = max(maxPath, root->val + lmax + rmax);

        return root->val + max(lmax, rmax);

    }

    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        dfs(root, maxPath);
        return maxPath;
    }
};