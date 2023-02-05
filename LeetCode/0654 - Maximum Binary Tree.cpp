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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        if (nums.empty()) return NULL;
        
        int m = 0, it = 0;        
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > m)
                m = nums[i], it = i;
        
        vector<int> l(nums.begin(), nums.begin() + it);
        vector<int> r(nums.begin() + it + 1, nums.end());
        
        TreeNode* root = new TreeNode(m);
        root->left = constructMaximumBinaryTree(l);
        root->right = constructMaximumBinaryTree(r);
        
        return root;
    }
};