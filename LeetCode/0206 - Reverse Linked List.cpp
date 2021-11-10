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

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* newHead = NULL;
        
        while(head)
        {
            ListNode* tmp = head->next;
            head->next = newHead;
            newHead = head;
            head = tmp;
        }
        
        return newHead;
    }
};