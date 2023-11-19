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
    // Find LCA
    // Traverse from start_node to lca and lca to dest_node
    TreeNode* lca(TreeNode* root, int startValue, int destValue) {
        if (root == NULL) {
            return NULL;
        }

        if (root->val == startValue) {
            return root;
        }

        if (root->val == destValue) {
            return root;
        }

        TreeNode* left = lca(root->left, startValue, destValue);
        TreeNode* right = lca(root->right, startValue, destValue);

        if (left && right) {
            return root;
        }
        if (left) {
            return left;
        }
        if (right) {
            return right;
        }

        return NULL;
    }

    // Backtracking approach
    bool findPath(int value, TreeNode* root, string& ans) {
        if (root == NULL) {
            return false;
        }

        //If not found,  we have our path ready
        // So, no need to explore further
        // Simply return true from here
        if (root->val == value) {
            return true;
        }

        ans.push_back('L');
        if(findPath(value, root->left, ans)) {
            return true;
        }
        ans.pop_back();

        //Try to find node in right direction
        ans.push_back('R');
        if (findPath(value, root->right, ans)) {
            return true;
        }
        ans.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* parentNode = lca(root, startValue, destValue);
        // cout<<parentNode->val<<endl;
        string lca_to_start = "";
        string lca_to_dest = "";

        // string ans="";

        findPath(startValue, parentNode, lca_to_start);
        findPath(destValue, parentNode, lca_to_dest);

        for (auto& c : lca_to_start) c = 'U';
        return lca_to_start + lca_to_dest;
    }  
};