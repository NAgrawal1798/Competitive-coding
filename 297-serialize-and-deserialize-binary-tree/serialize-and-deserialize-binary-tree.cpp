/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    // Level order traversal
    string serialize(TreeNode* root) {
        string s = "";
        if(!root) {
            return s;
        }
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()) {
            TreeNode * temp = q.front();
            q.pop();
            if(!temp) {
                s.append("null,");
            } else {
                s.append(to_string(temp->val) + ",");
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        cout<<s<<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) {
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s,str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            getline(s,str,',');
            if(str == "null") {
                node->left = NULL;
            } else {
                TreeNode* left = new TreeNode(stoi(str));
                node->left = left;
                q.push(node->left);
            }
            getline(s,str, ',');
            if(str == "null") {
                node->right = NULL;
            } else {
                TreeNode* right = new TreeNode(stoi(str));
                node->right = right;
                q.push(right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));