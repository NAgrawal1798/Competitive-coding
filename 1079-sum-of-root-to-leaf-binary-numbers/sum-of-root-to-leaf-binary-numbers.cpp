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
    // Make an iteration from root to leaf for all possible paths
    void helper(vector<string>&s, TreeNode* root, string temp){
        if (root == NULL) {
            return;
        }
        // leaf node
        if(root->left == NULL && root->right == NULL) {
            s.push_back(temp + to_string(root->val));
            return;
        }
        // left subtree
            helper(s, root->left, temp + to_string(root->val));
        // right subtree
            helper(s, root->right, temp + to_string(root->val));
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        vector<string>s;
        helper(s, root, "");
        for(int i=0; i<s.size(); i ++) {
            int number = 0;
            string temp = s[i];
            int j=0;
            cout<<temp<<endl;
            while(j<temp.size()) {
                if(temp[temp.size() - j-1] == '1') {
                    number += pow(2, j);
                }
                j++;
            }
            ans += number;
        }
        return ans;
    }
};