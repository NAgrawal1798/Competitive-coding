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
    void solve(TreeNode* root, int &ans, int &m, int h) {
        if (root == NULL) {
            return;
        }
        if (m<h) {
            ans = root->val;
            m=h;
        }
        solve(root->left, ans, m, h+1);
        solve(root->right, ans, m, h+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        int m = -1;
        int h=0;
        int ans;
        solve(root, ans, m, h);
        return ans;
        // int ans;
        // if (root == NULL) {
        //     return ans;
        // }

        // queue<TreeNode*>q;
        // q.push(root);

        // while(!q.empty()) {
        //     int size = q.size();

        //     for (int i=0; i<size; i++) {
        //         TreeNode* node = q.front();
        //         if (i== 0) {
        //             ans = node->val;
        //         }
        //         if (node->left) {
        //             q.push(node->left);
        //         }
        //         if (node->right) {
        //             q.push(node->right);
        //         }
        //         q.pop();
        //     }
        // }

        // return ans;
    }
};