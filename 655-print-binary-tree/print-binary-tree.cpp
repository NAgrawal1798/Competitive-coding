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
    // Find the height
    int getHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    // Make a recrusion to store the values in the matrix
    void fillTree(TreeNode* root, int row, int mid, vector<vector<string>>&ans, int height){

        if (root == NULL) {
            return;
        }
        ans[row][mid] = to_string(root->val);
        // int offset = 1;
        int offset = pow(2, height-row-1);
        fillTree(root->left, row + 1, mid - offset, ans, height);
        fillTree(root->right, row + 1, mid+ offset, ans, height);
    }



    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root)-1;
        int n = (1 << (height+1)) - 1;

        vector<vector<string>>ans(height+1, vector<string>(n, ""));

        int mid = (n-1)/2;
        fillTree(root, 0, mid, ans, height);

        return ans;
    }
};