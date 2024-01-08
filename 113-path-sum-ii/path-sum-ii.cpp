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
    // recursive function
    void helper(vector<vector<int>>&ans, vector<int>v, TreeNode* root, int targetSum, int sum) {
        // base case
        if (root->left == NULL && root->right == NULL) {
            cout<<sum<<endl;
            if (sum - targetSum == 0) {
                ans.push_back(v);
            }
        }
        // left traversal
        if (root->left) {
            v.push_back(root->left->val);
            helper(ans, v, root->left,  targetSum, sum + root->left->val);
            v.pop_back();
        }

        // right traversal
        if (root->right) {
            v.push_back(root->right->val);
            helper(ans, v, root->right, targetSum, sum + root->right->val);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>v;
        if (!root) {
            return ans;
        }
        v.push_back(root->val);
        int sum = root->val;
        helper(ans, v, root, targetSum, sum);
        return ans;
    }
};