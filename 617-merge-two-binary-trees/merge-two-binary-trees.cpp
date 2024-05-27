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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) {
            return t2;
        }
        if (t2 == NULL) {
            return t1;
        }
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }

    // TreeNode* helper(TreeNode* root1, TreeNode* root2) {
        // if (root1 == NULL && root2 == NULL) {
        //     return NULL;
        // }
        // int val1 = root1 != NULL ? root1->val : 0;
        // int val2 = root2 != NULL ? root2->val : 0;
        // TreeNode* node = new TreeNode(val1 + val2);
        // TreeNode* leftRoot1 = root1 != NULL ? root1->left : NULL;
        // TreeNode* leftRoot2 = root2 != NULL ? root2->left : NULL;
        // TreeNode* rightRoot1 = root1 != NULL ? root1->right : NULL;
        // TreeNode* rightRoot2 = root2 != NULL ? root2->right : NULL;
        // node->left = helper(leftRoot1, leftRoot2);
        // node->right = helper(rightRoot1, rightRoot2);
        // return node;
    // }
};