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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0) {
            return head;
        }
        ListNode *nthNode = head;
        for(int i = 0; i < (n-1) && nthNode != nullptr; ++i, nthNode = nthNode->next);
        if (nthNode == NULL) {
            return head;
        }
        ListNode **pNode = &head;
        for (; nthNode->next != NULL; nthNode = nthNode->next, pNode = &((*pNode)->next));
        ListNode *rmNode = *pNode;
        *pNode = rmNode->next;
        delete rmNode;
        return head;
    }
};
