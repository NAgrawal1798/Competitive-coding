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

    int solve(TreeNode* root, int &count, int prev) {
        if (root == NULL) {
            return count;
        }

        if (prev <= root->val) {
            count++;
        }

        prev = max(prev, root->val);

        solve(root->left, count, prev);
        solve(root->right, count, prev);

        return count;

    }
    int goodNodes(TreeNode* root) {

        int count =0;
        int prev = root->val;
        return solve(root,count,prev);
        // TreeNode* head = root;

        // if (head == NULL) {
        //     return 0;
        // }

        // int ans = 0;

        // if (maxVal <= root->val) {
        //     maxVal = head->val;
        //     ans++;
        // }
        //     ans += goodNodes(head->left);
        //     ans += goodNodes(head->right);

        // return ans;
    }
};