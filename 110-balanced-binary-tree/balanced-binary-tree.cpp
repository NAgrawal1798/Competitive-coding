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
    // int height(TreeNode* root) {
    //     if (root == NULL) {
    //         return 0;
    //     }
    //     return 1+ max(height(root->left), height(root->right));
    // }
    // bool helper(TreeNode* root) {
    //     if (root == NULL) {
    //         return true;
    //     }
    //     int height_left_subtree = height(root->left);
    //     int height_right_subtree = height(root->right);

    //     if (abs(height_left_subtree - height_right_subtree) > 1) {
    //         return false;
    //     }
    //     return helper(root->left) && helper(root->right);
    // }
    int check(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int lh = check(root->left);
        if (lh == -1) {
            return -1;
        }
        int rh = check(root->right);
        if (rh == -1) {
            return -1;
        }
        if (abs(lh-rh) >1) {
            return -1;
        }
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        if (check(root) >= 0) {
            return true;
        }
        return false;
    }
};