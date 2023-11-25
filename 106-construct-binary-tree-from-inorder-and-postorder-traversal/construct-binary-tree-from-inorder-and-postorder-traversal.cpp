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
    // Inorder -> Left, Root, Right
    // Postorder -> Left, Right, Root
    // Preorder -> Root, Left, Right 

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inorder_start, int inorder_end,
    int postorder_start, int postorder_end, unordered_map<int, int>& mp) {
    if (inorder_start > inorder_end || postorder_start > postorder_end) {
        return nullptr;
    }

    int node_val = postorder[postorder_end];
    TreeNode* node = new TreeNode(node_val);

    int node_present_inorder = mp[node_val];
    int left_subtree_size = node_present_inorder - inorder_start;

    node->left = helper(inorder, postorder, inorder_start, node_present_inorder - 1,
                        postorder_start, postorder_start + left_subtree_size - 1, mp);
    node->right = helper(inorder, postorder, node_present_inorder + 1, inorder_end,
                         postorder_start + left_subtree_size, postorder_end - 1, mp);

    return node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> mp;
    int inorder_size = inorder.size();
    int postorder_size = postorder.size();

    for (int i = 0; i < inorder_size; i++) {
        mp[inorder[i]] = i;
    }

    return helper(inorder, postorder, 0, inorder_size - 1, 0, postorder_size - 1, mp);
}
};