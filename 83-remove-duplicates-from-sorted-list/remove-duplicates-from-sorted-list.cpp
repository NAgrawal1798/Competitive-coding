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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        set<int>s;

        ListNode* root = head;
        while(root) {
            s.insert(root->val);
            root = root->next;
        }

        ListNode* newHead = NULL;
        ListNode* current = NULL;
        for (auto it: s) {
            if (!newHead) {
                newHead = new ListNode(it);
                current = newHead;
            } else {
                current->next = new ListNode(it);
                current = current->next;
            }
        }
        return newHead;
    }
};