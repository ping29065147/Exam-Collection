/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        if (!original) return NULL;
        if (original == target) return cloned;
        
        TreeNode* a = getTargetCopy(original->left, cloned->left, target);
        TreeNode* b =getTargetCopy(original->right, cloned->right, target);
        
        return a ? a : b;
    }

};