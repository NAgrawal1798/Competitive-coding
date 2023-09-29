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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        addRow(root, val, depth, 1);
        return root;
    }

    void addRow(TreeNode* root, int val, int depth, int level) {
        if (root == nullptr) {
            return;
        }

        if (level == depth - 1) {
            TreeNode* leftSubtree = root->left;
            TreeNode* rightSubtree = root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = leftSubtree;
            root->right->right = rightSubtree;
        } else {
            addRow(root->left, val, depth, level + 1);
            addRow(root->right, val, depth, level + 1);
        }
    }
};
