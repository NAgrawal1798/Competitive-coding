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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) {
            return subRoot == NULL;
        }
        if (isSameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) {
            return true;
        }
        if (s == NULL || t == NULL) {
            return false;
        }
        if (s->val != t->val) {
            return false;
        }
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
};
