static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string removeDuplicates(string s)
    {
        string ret;
        
        for (auto& c : s)
        {
            if (!ret.empty() && ret.back() == c) ret.pop_back();
            else ret.push_back(c);
        }
        
        return ret;
    }
};