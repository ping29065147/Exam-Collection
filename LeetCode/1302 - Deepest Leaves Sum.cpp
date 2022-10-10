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
    int deepestLeavesSum(TreeNode* root)
    {
        int cnt = 0;
        findDeep(root, 0, cnt);
        return cnt;
    }
    
    void findDeep(TreeNode* root, int n, int &cnt)
    {
        if (n > d) d = n, cnt = 0;
        if (n == d) cnt += root->val;
        
        if (root->left) findDeep(root->left, n + 1, cnt);
        if (root->right) findDeep(root->right, n + 1, cnt);
    }
    
private:
    int d = 0;
};