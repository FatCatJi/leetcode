/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
	class Compare {
	public:
		bool operator() (ListNode *node1, ListNode *node2) {
			return (node1->val) > (node2->val);
		}
	};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // min heap
        vector<ListNode*> heap;
		for (auto l : lists) {
			if (l != nullptr) {
				heap.push_back(l);
			}
		}
		Compare greater;
        make_heap(heap.begin(), heap.end(), greater);
		ListNode *head = nullptr, **tailNext = &head;
		while (!heap.empty()) {
            pop_heap(heap.begin(), heap.end(), greater);
			ListNode* node = heap.back();
			*tailNext = node;
			tailNext = &(node->next);
			node = node->next;
			if (node != nullptr) {
				heap.back() = node;
                push_heap(heap.begin(), heap.end(), greater);
			} else {
				heap.pop_back();
			}
		}
		return head;
    }
};
