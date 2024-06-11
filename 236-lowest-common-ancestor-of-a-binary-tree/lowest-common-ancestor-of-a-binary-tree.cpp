/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return NULL;
        }
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        TreeNode* leftTree = helper(root->left, p , q);
        TreeNode* rightTree = helper(root->right, p, q);
        if (leftTree && rightTree) {
            return root;
        }
        if (leftTree) {
            return leftTree;
        }
        return rightTree;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q);
    }
};