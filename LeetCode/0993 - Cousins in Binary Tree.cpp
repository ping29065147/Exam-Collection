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
    bool isCousins(TreeNode* root, int x, int y)
    {
        inorder(root, x, y, -1, 0);
        return x_par != y_par && x_dep == y_dep;
    }
    
    void inorder(TreeNode* node, int x, int y, int par, int dep)
    {
        if (!node) return;
        
        if (x == node->val) x_par = par, x_dep = dep;
        else if (y == node->val) y_par = par, y_dep = dep;
        
        inorder(node->left, x, y, node->val, dep + 1);
        inorder(node->right, x, y, node->val, dep + 1);
    }
    
private:
    int x_par = 0, y_par = 0;
    int x_dep = 0, y_dep = 0;
};