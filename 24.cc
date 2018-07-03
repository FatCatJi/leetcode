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
    ListNode* swapPairs(ListNode* head) {
        ListNode *newHead = nullptr, **newTailNext = &newHead;
        while (head != nullptr) {
            ListNode *curNode = head;
            head = head->next;
            if (head != nullptr) {
                ListNode *nextNode = head;
                head = head->next;
                *newTailNext = nextNode;
                newTailNext = &(nextNode->next);
            }
            *newTailNext = curNode;
            newTailNext = &(curNode->next);
        }
        *newTailNext = nullptr;
        return newHead;
    }
};
