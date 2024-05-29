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
    // Left, Root, Right
    // inorder traversal
    void helper(TreeNode* root, vector<int>& ans) {
       if (root == NULL) {
            return;
       }
       helper(root->left,ans);
       ans.push_back(root->val);
       helper(root->right, ans);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        vector<int>ans;
        helper(root, ans);
        TreeNode* node = new TreeNode(-1);
        TreeNode* newroot = node;
        int n = ans.size();
        for(int i=0; i<n; i++) {
            node->right = new TreeNode(ans[i]);
            node = node->right;
        }
        return newroot->right;
    }
};