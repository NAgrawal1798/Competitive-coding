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
        if(root == NULL) {
            return NULL;
        }
        if(depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        if(depth == 2) {
                TreeNode* leftSubtree = root->left;
                TreeNode* rightSubtree = root->right;

                root->left = new TreeNode(val);
                root->right = new TreeNode(val);

                root->left->left = leftSubtree;
                root->right->right = rightSubtree;
            }
        else {
            root->left = addOneRow(root->left, val, depth-1);
            root->right = addOneRow(root->right, val, depth-1);
        }

        return root;
    }
};