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
    ListNode* mergeNodes(ListNode* head)
    {
        ListNode LN;
        ListNode* cur = &LN;
        int n = 0;
        head = head->next;
        
        while(head)
        {            
            n += head->val;
            if (head->val == 0)
            {
                ListNode* t = new ListNode(n);
                cur->next = t;
                cur = cur->next;
                n = 0;
            }
            head = head->next;
        }
        
        return LN.next;
    }
};