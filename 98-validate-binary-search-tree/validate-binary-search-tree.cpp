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

bool isValidBST(TreeNode* node, long long lower, long long upper) {
        if (node == nullptr) {
            return true;
        }

        if (node->val <= lower || node->val >= upper) {
            return false;
        }

        return isValidBST(node->left, lower, node->val) && isValidBST(node->right, node->val, upper);
    }
    bool isValidBST(TreeNode* root) {

                return isValidBST(root, LONG_MIN, LONG_MAX);


        // if (root == NULL) {
        //     return true;
        // }
        // bool isTrue = true;
        // bool rootVal = root->val;
        // if(root->left) {
        //     isTrue = rootVal > root->left->val ? true : false;
        // }
        // if(root->right) {
        //     isTrue = rootVal < root->right->val ? true : false;
        // }

        // return isTrue && isValidBST(root->left) && isValidBST(root->right);
    }
};