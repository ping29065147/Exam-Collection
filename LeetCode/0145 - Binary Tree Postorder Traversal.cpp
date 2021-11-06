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
    vector<int> postorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> S;
        vector<int> ret;
        
        if (root) S.push(root);
        while(!S.empty())
        {
            TreeNode* tmp = S.top();
            S.pop();
            ret.insert(ret.begin(), tmp->val);
            if (tmp->left) S.push(tmp->left);
            if (tmp->right) S.push(tmp->right);
        }
        
        return ret;
    }
};