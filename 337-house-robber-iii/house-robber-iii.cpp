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
    // PICK OR NOT PICK
    map<pair<TreeNode*, int>, int>mp;
    int helper(TreeNode* root, int canPick) {

        if (root == NULL) {
            return 0;
        }

        if (mp.find({root,canPick}) != mp.end()) {
            return mp[{root,canPick}];
        }

        int pick = 0;
        int notpick = 0;

        if (canPick) {
            int picked  = root->val + helper(root->left, 0) + helper(root->right, 0);
            int notpicked = 0 + helper(root->left, 1) + helper(root->right, 1);
            pick = max(picked, notpicked);
        } else {
            notpick = 0 + helper(root->left, 1) + helper(root->right, 1);
        }
        return mp[{root, canPick}] = max(pick,notpick);
    }
    int rob(TreeNode* root) {
        return max(helper(root, 1), helper(root, 0));
    }
};