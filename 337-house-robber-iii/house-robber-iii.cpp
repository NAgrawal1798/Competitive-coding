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
    map<pair<TreeNode*, bool>, int> mp;

    int helper(TreeNode* root, bool flag) {
        if (root == NULL) {
            return 0;
        }
        if (mp.find({root, flag}) != mp.end()) {
            return mp[{root, flag}];
        }

        int allowed = 0;
        int notAllowed = 0;

        if (flag) {
            int take = root->val + helper(root->left, false) + helper(root->right, false);
            int notTake = helper(root->left, true) + helper(root->right, true);
            allowed = max(take, notTake);
        } else {
            notAllowed = helper(root->left, true) + helper(root->right, true);
        }

        return mp[{root, flag}] = max(allowed, notAllowed);
    }

    int rob(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return helper(root, true);
    }
};
