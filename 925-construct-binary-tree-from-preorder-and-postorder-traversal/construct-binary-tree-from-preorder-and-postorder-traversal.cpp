// #include <vector>
// #include <unordered_map>
// using namespace std;

// class TreeNode {
// public:
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        unordered_map<int, int> postIndex;
        for (int i = 0; i < post.size(); ++i) {
            postIndex[post[i]] = i;
        }
        return buildTree(pre, post, 0, pre.size() - 1, 0, post.size() - 1, postIndex);
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& post, int preStart, int preEnd, int postStart, int postEnd, unordered_map<int, int>& postIndex) {
        if (preStart > preEnd || postStart > postEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(pre[preStart]);
        if (preStart == preEnd) {
            return root;
        }

        int leftRootVal = pre[preStart + 1];
        int leftRootPostIndex = postIndex[leftRootVal];
        int leftSubtreeSize = leftRootPostIndex - postStart + 1;

        root->left = buildTree(pre, post, preStart + 1, preStart + leftSubtreeSize, postStart, leftRootPostIndex, postIndex);
        root->right = buildTree(pre, post, preStart + leftSubtreeSize + 1, preEnd, leftRootPostIndex + 1, postEnd - 1, postIndex);

        return root;
    }
};
