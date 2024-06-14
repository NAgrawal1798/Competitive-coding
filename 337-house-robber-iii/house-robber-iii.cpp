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
    unordered_map<TreeNode*, int> dpTrue, dpFalse;

    int helper(TreeNode* root, bool flag) {
        if (root == NULL) {
            return 0;
        }
        if (flag && dpTrue.find(root) != dpTrue.end()) {
            return dpTrue[root];
        }
        if (!flag && dpFalse.find(root) != dpFalse.end()) {
            return dpFalse[root];
        }

        int allowed = 0;
        int notAllowed = 0;

        if (flag) {
            int take = root->val + helper(root->left, false) + helper(root->right, false);
            int notTake = helper(root->left, true) + helper(root->right, true);
            allowed = max(take, notTake);
            dpTrue[root] = allowed;
        } else {
            notAllowed = helper(root->left, true) + helper(root->right, true);
            dpFalse[root] = notAllowed;
        }

        return max(allowed, notAllowed);
    }

    int rob(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return helper(root, true);
    }
};
