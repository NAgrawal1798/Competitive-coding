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
    // this is O(n^2) approach
    // void reorderList(ListNode* head) {
    //     if (!head || !head->next || !head->next->next) {
    //         return;
    //     }
    //     ListNode* penultimate = head;
    //     while(penultimate->next->next) {
    //         penultimate = penultimate->next;
    //     }

    //     penultimate->next->next = head->next;
    //     head->next = penultimate->next;

    //     // Again set the penultimate to the last
    //     penultimate->next = NULL;

    //     reorderList(head->next->next);
    // }
    // O(n + n/2 + n) approach
    void reorderList(ListNode* head) {
        // base case : linkedlist is empty
        if(!head) {
            return;
        }

        // Finding the middle with the help of 2 pointer approach
        ListNode* temp = head;
        ListNode* half = head;
        while(temp->next && temp->next->next) {
            temp = temp->next->next;
            half = half->next;
        }

        // adding one bit in case of lists with even length
        if(temp->next) {
            half = half->next;
        }

        ListNode* prev = NULL;

        // Now reverse the second half
        while(half) {
            temp = half->next;
            half->next = prev;
            prev = half;
            half = temp;
        }

        half = prev;

        // After reversing the secondhalf , lets merge both the halfes
        while(head && half) {
            temp = head ->next;
            prev = half->next;
            head->next = half;
            half->next = temp;
            head=temp;
            half = prev;
        }

        if (head && head->next) {
            head->next->next = NULL;
        }
    }
};