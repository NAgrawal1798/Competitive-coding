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
    TreeNode* findDepth(TreeNode* root, int val, int depth, int level) {
        if (root == NULL) {
            return NULL;
        }
        if (level == (depth-1)) {
            TreeNode* left = new TreeNode(val);
            TreeNode* right = new TreeNode(val);
            left->left = root->left;
            right->right = root->right;
            root->left = left;
            root->right = right;
        } 
          TreeNode* leftTree =   findDepth(root->left,val, depth, level+1);
           TreeNode* rightTree =  findDepth(root->right, val, depth, level+1);
        
        return new TreeNode(root->val, leftTree, rightTree);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* ans = root;

        // Handled depth = 1 case
        if (depth == 1) {
            ans = new TreeNode(val);
            ans->left = root;
            return ans;
        }else {
            return findDepth(root, val, depth, 1);
        }

        return ans;
    }
};