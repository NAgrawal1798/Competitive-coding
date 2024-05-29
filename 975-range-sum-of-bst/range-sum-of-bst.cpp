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
private:
    void helper(TreeNode* root, vector<int>& nums) {
        if (root == NULL) {
            return;
        }
        helper(root->left, nums);
        nums.push_back(root->val);
        helper(root->right, nums);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        // inorder traversal
        if(root == NULL) {
            return 0;
        }
        int ans = 0;
        vector<int>nums;
        helper(root, nums);
        // Find the lower and upper bounds
        auto lowerIt = lower_bound(nums.begin(), nums.end(), low);
        auto upperIt = upper_bound(nums.begin(), nums.end(), high);

        // Sum the range
        int sum = 0;
        for (auto it = lowerIt; it != upperIt; ++it) {
            sum += *it;
        }
        return sum;
    }
};