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
    // recursion to solve the sum
    void helper(TreeNode* root, long long int targetSum, int &ans) {
        if (root == NULL) {
            return;
        }
        targetSum -= root->val;
        if(targetSum == 0) {
            ans++;
        }
        helper(root->left, targetSum, ans);
        helper(root->right, targetSum ,ans);
    }
    // recursion to start from every node
    void pathSumHelper(TreeNode* root, long long int targetSum, int &ans) {
        if (root == NULL) {
            return;
        }
        // solve the sum
        helper(root, targetSum, ans);
        pathSumHelper(root->left, targetSum, ans);
        pathSumHelper(root->right, targetSum, ans);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        pathSumHelper(root, targetSum, ans);
        return ans;
    }
};