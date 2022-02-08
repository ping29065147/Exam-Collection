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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* ret = new ListNode(-1);
        ListNode* cur = ret;
        int carry = 0;
        
        while(l1 || l2)
        {
            int sum = carry;
            if (l1 && l2) sum += l1->val + l2->val;
            else if (l1) sum += l1->val;
            else sum += l2->val;
            
            cur->next = new ListNode(sum % 10);
            carry = sum / 10;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            cur = cur->next;
        }
        if (carry) cur->next = new ListNode(1);
        
        return ret->next;
    }
};