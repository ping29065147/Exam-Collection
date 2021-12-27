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
    TreeNode* increasingBST(TreeNode* root)
    {
        return inorder(root, nullptr);
    }
    
    TreeNode* inorder(TreeNode* node, TreeNode* pre)
    {
        if (!node) return pre;
        
        TreeNode* ret = inorder(node->left, node);
        node->left = nullptr;
        node->right = inorder(node->right, pre);
        
        return ret;
    }
};