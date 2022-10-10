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
    int sumEvenGrandparent(TreeNode* root)
    {
        findGP(root, -1, -1);
        return cnt;
    }
    
    void findGP(TreeNode* root, int p, int gp)
    {
        if (gp % 2 == 0) cnt += root->val;        
        if (root->left) findGP(root->left, root->val, p);
        if (root->right) findGP(root->right, root->val, p);
    }
    
private:
    int cnt = 0;
};