static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string defangIPaddr(string address)
    {
        string ret;        
        for (auto& c : address) ret += (c == '.' ? "[.]" : string(1, c));
        return ret;
    }
};