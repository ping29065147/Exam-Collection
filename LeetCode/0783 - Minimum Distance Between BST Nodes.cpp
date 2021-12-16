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
    int minDiffInBST(TreeNode* root)
    {
        int cnt = INT_MAX;
        
        ret.push_back(root->val);
        inorder(root);
        sort(ret.begin(), ret.end());
        for (int i = 1; i < ret.size(); ++i) cnt = min(cnt, abs(ret[i] - ret[i - 1]));
        
        return cnt;
    }
    
    int inorder(TreeNode* root)
    {     
        if (root->left) ret.push_back(inorder(root->left));
        if (root->right) ret.push_back(inorder(root->right));     
        
        return root->val;
    }
    
private:
    vector<int> ret;
};