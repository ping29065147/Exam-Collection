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
    int diameterOfBinaryTree(TreeNode* root)
    { 
        inorder(root);
        return len;
    }
    
    int inorder(TreeNode* node)
    {
        if (!node) return 0;
        
        int l = inorder(node->left);
        int r = inorder(node->right);
        
        len = max(len, l + r);
        return max(l , r) + 1;
    }
    
private:
    int len = 0;
};