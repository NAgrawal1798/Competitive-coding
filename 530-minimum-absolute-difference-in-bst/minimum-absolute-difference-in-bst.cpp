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
    void helper(TreeNode* root, int &mini, int &nextNum) {
        if (root == NULL) {
            return;
        }
        helper(root->left, mini,nextNum);

        mini = min(mini, abs(root->val - nextNum));
        nextNum = root->val;

        helper(root->right, mini, nextNum);
    }
    int getMinimumDifference(TreeNode* root) {
        int mini = INT_MAX;
        int nextNum = INT_MAX;
        helper(root,mini, nextNum);
        return mini;
    }
};