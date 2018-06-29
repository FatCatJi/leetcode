class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int listLen = 0;
		for (ListNode *node = head; node != nullptr; node = node->next) {
			++listLen;
		}
		for (int t = 1; t < listLen; t *= 2) {
			ListNode *newHead = nullptr, **newTail = &newHead;
			while (head != nullptr) {
				ListNode *l1Head = nullptr, **l1Tail = &l1Head;
				for (int i = 0; i < t && head != nullptr; ++i) {
					*l1Tail = head;
					l1Tail = &(head->next);
					head = head->next;
				}
                *l1Tail = nullptr;
				ListNode *l2Head = nullptr, **l2Tail = &l2Head;
				for (int i = 0; i < t && head != nullptr; ++i) {
					*l2Tail = head;
					l2Tail = &(head->next);
					head = head->next;
				}
                *l2Tail = nullptr;
				while (l1Head != nullptr && l2Head != nullptr) {
					if (l1Head->val <= l2Head->val) {
						*newTail = l1Head;
						newTail = &(l1Head->next);
						l1Head = l1Head->next;
					} else {
						*newTail = l2Head;
						newTail = &(l2Head->next);
						l2Head = l2Head->next;
					}
				}
				if (l1Head != nullptr) {
					*newTail = l1Head;
					newTail = l1Tail;
				} else {
					*newTail = l2Head;
					newTail = l2Tail;
				}
			}
			head = newHead;
		}
		return head;
    }
};
