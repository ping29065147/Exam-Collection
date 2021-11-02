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
    bool isSymmetric(TreeNode* root)
    {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* l, TreeNode* r)
    {
        if (!l && !r) return true;
        if ((!l && r) || (l && !r) || (l->val != r->val)) return false;
        return isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left);
    }
};