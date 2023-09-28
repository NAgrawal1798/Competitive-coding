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
    bool isEvenOddTree(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int level = 1;
        
        while(!q.empty() && q.front()!=NULL) {
            vector<int>values;
            while(q.front() != NULL) {
                TreeNode* node = q.front();
                values.push_back(node->val);
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            if (level%2==0) {
                if(values.size() > 1) {
                for (int i=0;i<values.size()-1; i++) {
                    if(values[i]%2==0 && values[i+1]%2==0 && values[i] > values[i+1]) {
                        continue;
                    } else {
                        return false;
                    }
                }
                } else {
                    if (values.size() == 1 && (values[0]%2 !=0)) {
                        return false;
                    }
                }
            } else {
                if (values.size() > 1) {
               for (int i=0;i<values.size()-1; i++) {
                    if(values[i]%2!=0 && values[i+1]%2!=0 && values[i] < values[i+1]) {
                        continue;
                    } else {
                        return false;
                    }
                }
                }
                else {
                    if (values.size() == 1 && (values[0]%2 ==0)) {
                        return false;
                    }
                }
            }
            level++;
            q.pop();
            q.push(NULL);
        }

        return true;
    }
};