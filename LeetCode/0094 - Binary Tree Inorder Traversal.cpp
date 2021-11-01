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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        stack<TreeNode*> S;
        TreeNode* cur;
        
        while(root || !S.empty())
        {
            while(root) S.push(root), root = root->left;
            cur = S.top(), S.pop();
            ret.push_back(cur->val);
            root = cur->right;
        }     
            
        return ret;
    }
};