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
    int height(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        // use queue to solve this question
        // find height of this binary tree
        int h = height(root);
        vector<int>ans(h, -1);
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;

        while(!q.empty()) {
            int size = q.size();

            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (ans[level] == -1) {
                    ans[level] = node->val;
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
                if (node->left != NULL) {
                    q.push(node->left);
                }
            }
            level++;
        }
        return ans;
    }
};