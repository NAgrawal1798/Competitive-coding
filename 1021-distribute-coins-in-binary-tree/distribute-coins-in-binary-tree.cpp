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
    int moves = 0;
    int distributeCoinsHelper(TreeNode* root) {
         if (root ==  nullptr) {
            return 0;
        }
        int left  = distributeCoinsHelper(root->left);
        int right = distributeCoinsHelper(root->right);
        moves += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
    int distributeCoins(TreeNode* root) {
       distributeCoinsHelper(root);
       return moves;
    }
};