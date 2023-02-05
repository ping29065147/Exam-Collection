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
    TreeNode* bstToGst(TreeNode* root)
    {
        if (!root) return root;
        
        if (root->right) root->right = bstToGst(root->right);
        
        sum += root->val;
        root->val = sum;
        
        if (root->left) root->left = bstToGst(root->left);
        
        return root;
    }
    
private:
    int sum = 0;
};