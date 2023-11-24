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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr) {
            return head;
        }
        int size = 0;
        ListNode* current = head;
        ListNode* lastPointer = nullptr;
        while(current) {
            size++;
            if (current->next == nullptr) {
                lastPointer = current;
            }
            current = current->next;
        }
        k = k%size;
        // cout<<lastPointer->val<<endl;

        int iterate = size - k;
        ListNode* root = head;
        ListNode* temp = head;
        lastPointer->next = root;
        cout<<iterate<<endl;
        for (int i=1; i<iterate; i++) {
            temp = temp->next;
        }
        cout<<temp->val<<endl;
        root = temp->next;
        temp->next = nullptr;
        return root;        
    }
};