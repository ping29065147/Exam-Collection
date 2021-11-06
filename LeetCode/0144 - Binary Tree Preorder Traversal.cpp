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
    vector<int> preorderTraversal(TreeNode* root)
    { 
        stack<TreeNode*> S;
        vector<int> ret;
        
        if(root) S.push(root);
        while(!S.empty())
        {
            TreeNode* tmp = S.top();
            S.pop();
            ret.push_back(tmp->val);
            if (tmp->right) S.push(tmp->right);
            if (tmp->left) S.push(tmp->left);
        }
        
        return ret;
    }
};