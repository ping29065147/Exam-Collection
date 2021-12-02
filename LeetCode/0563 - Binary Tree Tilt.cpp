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
    int findTilt(TreeNode* root)
    {
        int tilt = 0;
        inorder(root, tilt);
        return tilt;
    }
    
    int inorder(TreeNode* node, int& tilt)
    {
        if (!node) return 0;
        
        int l = inorder(node->left, tilt);
        int r = inorder(node->right, tilt);
        
        tilt += abs(l - r);
        return l + r + node->val;
    }
};