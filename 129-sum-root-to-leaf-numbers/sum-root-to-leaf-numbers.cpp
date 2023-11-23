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
    void helper(TreeNode* root, int& ans, string s) {
        if (root == NULL) {
            return;
        }
        s += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            ans += stoi(s);
            return;
        }
        helper(root->left, ans, s);
        helper(root->right, ans, s);
        return;
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        string s = "";
        helper(root, ans, s);
        return ans;
    }
};