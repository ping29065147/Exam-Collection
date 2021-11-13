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
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> ret;  
        if (root) findTree(root, "", ret);
        return ret;
    }
    
    void findTree(TreeNode* node, string str, vector<string>& ret)
    {
        if (!node->left && !node->right) ret.push_back(str + to_string(node->val));
        if (node->left) findTree(node->left, str + to_string(node->val) + "->", ret);
        if (node->right) findTree(node->right, str + to_string(node->val) + "->", ret);
    }
};