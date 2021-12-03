/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
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
    vector<int> preorder(Node* root)
    {
        if (!root) return {};
        
        ret.push_back(root->val);
        for (auto& i : root->children) preorder(i);
        
        return ret;
    }
private:
    vector<int> ret;
};