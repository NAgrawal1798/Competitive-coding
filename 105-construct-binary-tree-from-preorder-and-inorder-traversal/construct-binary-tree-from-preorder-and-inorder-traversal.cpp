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
 
 // preorder => Root, Left, Right
 // inorder => Left, Root, Right
class Solution {
public:
    TreeNode* helper(vector<int>& preorder, unordered_map<int,int>&mp, int& index, int i, int j) {
        
        // base case
        if(i >j) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[index++]);

        int mid = mp[root->val];
        root->left = helper(preorder, mp, index, i, mid - 1);
        root->right = helper(preorder, mp, index, mid + 1, j);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // create a hashmap to store the indices of elements in the inorder traversal
        unordered_map<int, int>mp; // value,index
        int size = preorder.size();
        for(int i=0; i<size; i++) {
            mp[inorder[i]] = i;
        }
        int index = 0;

        return helper(preorder, mp, index, 0, inorder.size() - 1);
    }
};