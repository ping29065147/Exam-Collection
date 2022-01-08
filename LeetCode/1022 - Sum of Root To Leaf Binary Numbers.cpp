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
    int sumRootToLeaf(TreeNode* root)
    {
        int sum = 0;
        inorder(root, 0, sum);
        return sum;
    }
    
    void inorder(TreeNode* node, int n, int& sum)
    {
        if (!node) return;
        
        int t = (n << 1) + node->val;
        
        if (!node->left && !node->right)
        {
            sum += t;
            return;
        }
        
        inorder(node->left, t, sum);
        inorder(node->right, t, sum);
    }
};