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
    bool isPalindrome(ListNode* head)
    {
        vector<int> num;
        
        while(head)
        {
            num.push_back(head->val);
            head = head->next;
        }
        
        for (int i = 0, j = num.size() - 1; i < j; ++i, --j)
        {
            if (num[i] != num[j]) return false;
        }
        
        return true;
    }
};