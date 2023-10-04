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
class CBTInserter {
public:
    queue<TreeNode*>q;
    TreeNode* root1 = nullptr;

    CBTInserter(TreeNode* root)
    {
        root1 = root;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* f = q.front();
            if(f->left)q.push(f->left);
            if(f->right)q.push(f->right);
            if(f->left && f->right)q.pop();
            else
            break;
        }
    }
    
    int insert(int val) 
    {
        TreeNode* curr = new TreeNode(val);
        TreeNode* f = q.front();
        if(f->left == nullptr)f->left = curr;
        else
        {
            f->right = curr;
            q.pop();
        }
        q.push(curr);
        return f->val;
        
    }
    
    TreeNode* get_root() 
    {
        return root1;   
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */