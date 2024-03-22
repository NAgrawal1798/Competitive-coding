class Solution {
public:
    void helper(TreeNode* root, int& count, int& sum, int& n) { // Pass sum and n by reference
        // base case
        if (root == NULL){
            return;
        }
        int leftSum = 0, leftN = 0;
        int rightSum = 0, rightN = 0;
        helper(root->left, count, leftSum, leftN); // Update leftSum and leftN by reference
        helper(root->right, count, rightSum, rightN); // Update rightSum and rightN by reference

        sum = root->val + leftSum + rightSum; // Update sum with the sum of current node's value and its children
        n = 1 + leftN + rightN; // Update n with the count of nodes in the subtree including current node

        if (root->val == (sum/n)) {
            count++;
        }
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        int sum = 0;
        int n = 0;
        helper(root, count, sum, n);
        return count;
    }
};
