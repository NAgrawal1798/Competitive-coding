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
    //  solve using recursion
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return helper(nums, 0, n);
    }

    TreeNode* helper(vector<int>& nums, int l, int r) {
        if(l==r) {
            return NULL;
        }
        int maxi = findMaxi(nums, l, r);
        TreeNode* node = new TreeNode(nums[maxi]);
        node->left = helper(nums, l, maxi);
        node->right = helper(nums, maxi+1, r);
        return node;
    }

    int findMaxi(vector<int>& nums, int l, int r) {
        int maxi = l;
        for(int i=l; i<r; i++) {
            if(nums[maxi] < nums[i]) {
                maxi = i;
            }
        }

        return maxi;
    }
};