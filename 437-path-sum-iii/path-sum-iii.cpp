class Solution {
public:
    int p(TreeNode* root, long long s) {
        if(!root) {
            return 0;
        }
        int res = 0;
        s -= root->val;
        if(s == 0) {
            res += 1;
        }
        return res += p(root->right, s) + p(root->left, s);
    }
    int pathSum(TreeNode* root, int s) {
       if(!root) {
        return 0;
       }
       return pathSum(root->left, s) + p(root, s) + pathSum(root->right, s);
    }
};