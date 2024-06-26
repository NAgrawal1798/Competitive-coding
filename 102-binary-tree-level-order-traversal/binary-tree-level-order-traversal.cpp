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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>>ans;
        if(root == NULL) {
            return ans;
        }
        while(!q.empty()) {
            int size = q.size();
            vector<int>temp;
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
                temp.push_back(node->val);
            }
            if(temp.size()) {
                ans.push_back(temp);
            }
        }
        return ans;
    }
};