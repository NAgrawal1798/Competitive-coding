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
        bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int prevValue = (level % 2 == 0) ? 0 : INT_MAX;

            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Check value based on the level's parity
                if ((level % 2 == 0 && (node->val % 2 == 1) && node->val > prevValue) ||
                    (level % 2 != 0 && (node->val % 2 == 0) && node->val < prevValue)) {
                    prevValue = node->val;
                } else {
                    return false;
                }

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            level++;
        }

        return true;
    }
};