/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    bool hasCycle(ListNode *head)
    {
        while(head)
        {
            if (head->val == 111111) return true;
            head->val = 111111;
            head = head->next;           
        }
        
        return false;
    }
};