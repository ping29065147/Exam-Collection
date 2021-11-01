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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* cur = head;
        
        while(cur && cur->next)
        {
            if (cur->val == cur->next->val) cur->next = cur->next->next;
            else cur = cur->next;
        }        
        
        return head;
    }
};