/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    int findSecondMinimumValue(TreeNode* root)
    {
        return _find(root, root->val); 
    }
    
    int _find(TreeNode* node, int first)
    {
        if (!node) return -1;
        if (node->val != first) return node->val;
        int l = _find(node->left, first), r = _find(node->right, first);
        return (l == -1 || r == -1) ? max(l, r) : min(l, r);
    }
};