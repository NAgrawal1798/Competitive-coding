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

    TreeNode* parent(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return NULL;
        }

        if (root->val == p->val) {
            return root;
        }
        if(root->val == q->val) {
            return root;
        }

        TreeNode* leftTree = parent(root->left, p, q);
        TreeNode* rightTree = parent(root->right, p, q);

        if (leftTree != NULL && rightTree !=NULL) {
            return root;
        }
        if (leftTree !=NULL) {
            return leftTree;
        }
        else {
            return rightTree;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return NULL;
        }
        return parent(root, p, q);
    }
};