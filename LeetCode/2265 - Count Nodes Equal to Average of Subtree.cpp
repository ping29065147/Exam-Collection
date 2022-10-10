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
    int averageOfSubtree(TreeNode* root)
    {
        return get<2>(getCnt(root));
    }
    
    tuple<int, int, int> getCnt(TreeNode* root)
    {
        if (!root) return {0, 0, 0};
        
        auto [Lval, Lcnt, Lans] = getCnt(root->left);
        auto [Rval, Rcnt, Rans] = getCnt(root->right);
        
        int val = Lval + Rval + root->val;
        int cnt = Lcnt + Rcnt + 1;
        int ans = Lans + Rans + (root->val == val / cnt);
        
        return {val, cnt, ans};
    }
};