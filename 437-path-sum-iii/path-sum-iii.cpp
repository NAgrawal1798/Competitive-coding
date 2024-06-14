#include <iostream>
#include <unordered_map>

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
    void helper(TreeNode* root, long long targetSum, int& ans) {
        if (root == NULL) {
            return;
        }
        
        targetSum -= root->val;
        if (targetSum == 0) {
            ans++;
        }
        
        helper(root->left, targetSum, ans);
        helper(root->right, targetSum, ans);
    }

    void pathSumHelper(TreeNode* root, long long targetSum, int& ans) {
        if (root == NULL) {
            return;
        }
        
        helper(root, targetSum, ans);
        pathSumHelper(root->left, targetSum, ans);
        pathSumHelper(root->right, targetSum, ans);
    }

    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        pathSumHelper(root, targetSum, ans);
        return ans;
    }
};
