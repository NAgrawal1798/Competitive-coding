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
    bool check(ListNode* head, int k) {
        while(k--) {
            if (head == NULL) {
                return false;
            }
            head = head->next;
        }
        return true;
    }
    ListNode* reverseK(ListNode* head, int k) {
        if (head == NULL || !check(head, k)) {
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next1 = NULL;
        ListNode* first = head;

        int tempK=k;
        while(tempK--) {
            next1 = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next1;
        }
        first->next = reverseK(curr, k);
        return prev;

    }
    ListNode* swapPairs(ListNode* head) {
        return reverseK(head, 2);
    }
};