/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
// Function to convert sorted array to a balanced binary search tree
TreeNode* sortedArrayToBST(const std::vector<int>& nums, int start, int end) {
    if (start > end) {
        return NULL;
    }

    // Find the middle element of the current subarray
    int mid = start + (end - start) / 2;

    // The middle element becomes the root
    TreeNode* root = new TreeNode(nums[mid]);

    // Recursively construct the left subtree and make it left child of root
    root->left = sortedArrayToBST(nums, start, mid - 1);

    // Recursively construct the right subtree and make it right child of root
    root->right = sortedArrayToBST(nums, mid + 1, end);

    return root;
}

// Helper function to initiate the recursive function call
TreeNode* sortedArrayToBST(const std::vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>nums;
        while(head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(nums);
    }
};