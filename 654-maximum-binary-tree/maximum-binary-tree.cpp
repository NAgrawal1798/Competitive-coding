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

    int findMaxValue(vector<int>& nums, int l, int r) {
        int max_i = l;
        for (int i = l; i < r; i++) {
            if (nums[max_i] < nums[i])
                max_i = i;
        }
        return max_i;
    }

    TreeNode* construct(vector<int>& nums, int left, int right) {
        if (left == right) {
            return NULL;
        }
        int max_i = findMaxValue(nums, left, right);
        TreeNode* root = new TreeNode(nums[max_i]);
        root->left = construct(nums, left, max_i);
        root->right = construct(nums, max_i + 1, right);
        return root;

    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size());
    }
};