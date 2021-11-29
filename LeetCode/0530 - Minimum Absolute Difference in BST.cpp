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
    int getMinimumDifference(TreeNode* root)
    {
        int ret = INT_MAX, pre = -1;
        inorder(root, pre, ret);
        return ret;
    }
    
    void inorder(TreeNode* node, int& pre, int& ret)
    {
        if (!node) return;
        inorder(node->left, pre, ret);
        if (pre != -1) ret = min(ret, node->val - pre);
        pre = node->val;
        inorder(node->right, pre, ret);
    }
};