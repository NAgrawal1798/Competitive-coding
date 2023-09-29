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

    void recursion (TreeNode *root, int level, vector<int> &ans) {
        if (root == NULL) {
            return;
        }
        if (ans.size() < level) {
            ans.push_back(root->val);
        }
        recursion(root->right, level+1, ans);
        recursion(root->left, level+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        recursion(root, 1, ans);
        return ans;
        // vector<int>ans;

        // if (root == NULL) {
        //     return ans;
        // }

        // queue<TreeNode*>q;
        // q.push(root);

        // while(!q.empty()) {
        //     int size = q.size();

        //     for (int i=0; i<size; i++) {
        //         TreeNode* node = q.front();
        //         if (i== size-1) {
        //             ans.push_back(node->val);
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