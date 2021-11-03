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
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return BST(0, nums.size() - 1, nums);
    }
    
    TreeNode* BST(int l, int r, vector<int>& nums)
    {
        if (l > r) return NULL;
        
        int m = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        
        root->left = BST(l, m - 1, nums);
        root->right = BST(m + 1, r, nums);
        return root;
    }
};