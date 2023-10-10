class Solution {
public:
    int helper(TreeNode* root, int& max_ans) {
        if (root == nullptr) {
            return 0;
        }

        int leftPath = helper(root->left, max_ans);
        int rightPath = helper(root->right, max_ans);

        int leftUnivaluePath = 0;
        int rightUnivaluePath = 0;

        if (root->left && root->left->val == root->val) {
            leftUnivaluePath = leftPath + 1;
        }

        if (root->right && root->right->val == root->val) {
            rightUnivaluePath = rightPath + 1;
        }

        max_ans = max(max_ans, leftUnivaluePath + rightUnivaluePath);
        return max(leftUnivaluePath, rightUnivaluePath);
    }

    int longestUnivaluePath(TreeNode* root) {
        int max_ans = 0;
        helper(root, max_ans);
        return max_ans;
    }
};
