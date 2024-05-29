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
    void helper(TreeNode* node, int &ans, string num) {
        // Base case
        if(node == NULL) {
            return;
        }
        // Required case
        if(node->left == NULL && node->right == NULL) {
            ans += stoi(num + to_string(node->val), 0, 2);
        }
        if(node->left) {
            helper(node->left, ans, num + to_string(node->val));
        }
        if(node->right) {
            helper(node->right, ans, num + to_string(node->val));
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int ans = 0;
        helper(root, ans, "");
        return ans;
    }
};