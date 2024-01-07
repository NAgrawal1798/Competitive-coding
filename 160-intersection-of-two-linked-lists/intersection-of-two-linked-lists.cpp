/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;

        ListNode* nodeA = headA;
        ListNode* nodeB = headB;
        while(nodeA || nodeB) {
            if (nodeA) {
                len1++;
                nodeA = nodeA->next;
            }
            if (nodeB) {
                len2++;
                nodeB = nodeB->next;
            }
        }
        int maxLen = len1 < len2 ? len2 : len1;
        int diff = abs(len1 - len2);
        if (maxLen == len1) {
            ListNode* nodeAA = headA;
            ListNode* nodeBB = headB;
            while(diff--) {
                nodeAA = nodeAA->next;
            }

            while(nodeAA != nodeBB) {
                nodeAA = nodeAA->next;
                nodeBB = nodeBB->next;
            } 
            return nodeAA;
        } else {
            ListNode* nodeAA = headA;
            ListNode* nodeBB = headB;
            while(diff--) {
                nodeBB = nodeBB->next;
            }
            while(nodeAA != nodeBB) {
                nodeAA = nodeAA->next;
                nodeBB = nodeBB->next;
            } 
            return nodeAA;

        }

    }
};