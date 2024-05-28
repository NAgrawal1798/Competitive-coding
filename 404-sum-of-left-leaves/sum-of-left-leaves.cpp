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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root ==NULL) {
            return 0;
        }
        int sum = 0;
        helper(root, sum);
        return sum;
    }
    void helper(TreeNode* root, int &sum) {
        if (root == NULL) {
            return;
        }
        if (root->left != NULL) {
            if (root->left->left == NULL && root->left->right == NULL) {
                sum += root->left->val;
            }
        }
        if (root->left != NULL) {
            helper(root->left, sum);
        }
        if (root->right != NULL) {
            helper(root->right, sum);
        }
    }
};