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
    void inorder(vector<int>&v, TreeNode* root) {
        if(!root) {
            return;
        }
        inorder(v, root->left);
        v.push_back(root->val);
        inorder(v, root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>v;
        inorder(v,root);

        TreeNode* newRoot = new TreeNode(v[0]);

        TreeNode* curr  = newRoot;

        for (int i=1; i<v.size(); i++) {
            curr->right = new TreeNode(v[i]);
            curr = curr->right;
        }

        return newRoot;

    }
};