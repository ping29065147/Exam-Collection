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
    vector<double> averageOfLevels(TreeNode* root)
    {
        if (!root) return {};
        
        vector<double> ret;
        queue<TreeNode*> Q;
        
        Q.push(root);
        while(!Q.empty())
        {
            int S = Q.size();
            double sum = 0;
            
            for (int i = 0; i < S; ++i)
            {
                TreeNode* tmp = Q.front(); Q.pop();
                sum += tmp->val;
                if (tmp->left) Q.push(tmp->left);
                if (tmp->right) Q.push(tmp->right);
            }
            
            ret.push_back(sum / S);
        }
        
        return ret;
    }
};