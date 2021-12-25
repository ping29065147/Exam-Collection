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
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> a, b;
        
        inorder(root1, a);
        inorder(root2, b);
        
        return a == b;
    }
    
    void inorder(TreeNode* node, vector<int>& V)
    {
        if (!node) return;
        if (!node->left && !node->right) V.push_back(node->val);
        
        inorder(node->left, V);
        inorder(node->right, V);
    }
};