class Solution {
public:
    ListNode* reverse(ListNode* head, int diff) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;

        while (diff--) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* node = &dummy;
        
        for (int i = 0; i < left - 1; ++i) {
            node = node->next;
        }
        
        ListNode* start = node->next;
        ListNode* end = start;
        
        for (int i = 0; i < right - left; ++i) {
            end = end->next;
        }
        
        ListNode* afterEnd = end->next;
        end->next = nullptr;

        node->next = reverse(start, right - left + 1);
        start->next = afterEnd;
        
        return dummy.next;
    }
};
