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
    string tree2str(TreeNode* root)
    {
        if (!root) return "";
        
        string str = to_string(root->val);
        if (!root->left && !root->right) return str;
        str += "(" + tree2str(root->left) + ")";
        if (root->right) str += "(" + tree2str(root->right) + ")";
        
        return str;
    }

};