static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isValid(string s)
    {
        if (s.size() % 2) return false;
        
        unordered_map<char, char> dict = { {')', '('}, {']', '['}, {'}', '{'} };
        stack<char> Stk;
        
        for (auto& c : s)
        {
            if (!Stk.empty() && Stk.top() == dict[c]) Stk.pop();
            else Stk.push(c);
        }
        
        return Stk.empty();
    }
};