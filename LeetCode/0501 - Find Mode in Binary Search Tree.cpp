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
    vector<int> findMode(TreeNode* root)
    {
        unordered_map<int, int> M;
        vector<int> ret;
        int Max = 0;
        
        inorder(root, M, Max);
        for (auto& [i, j] : M)
        {
            if (j == Max) ret.push_back(i);
        }
        
        return ret;
    }
    
    void inorder(TreeNode* node, unordered_map<int, int>& M, int& Max)
    {
        if (!node) return;
        inorder(node->left, M, Max);
        Max = max(Max, ++M[node->val]);
        inorder(node->right, M, Max);
    }
};