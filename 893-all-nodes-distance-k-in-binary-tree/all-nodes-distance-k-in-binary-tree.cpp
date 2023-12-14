/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Store parent child relationship
    // Then apply bfs

    void traverse(TreeNode* root, map<int,vector<int>>&mp) {
        if (root == NULL) {
            return;
        }
        if (root->left) {
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
            traverse(root->left, mp);
        }
        if (root->right) {
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
            traverse(root->right, mp);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<int,vector<int>>mp;
        // Have parent child relationship
        traverse(root, mp);

        // Apply BFS on it
        vector<int>ans;
        vector<int>visited(500, 0);
        queue<int>q;
        q.push(target->val);
        int size = 0;
        while(!q.empty()) {
            int s = q.size();
            for (int i=0; i<s; i++) {
                int node = q.front();
                q.pop();
                visited[node] = 1;
                cout<<node<<endl;
                if (size == k) {
                    ans.push_back(node);
                }
                for (auto it: mp[node]) {
                    if (!visited[it]) {
                       q.push(it);
                    }
                }
            }
            cout<<endl;
            size++;
        }

        return ans;
    }
};