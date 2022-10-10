static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minPartitions(string n)
    {
        char c = '0';        
        for (auto& i : n) c = max(c, i);            
        return c - '0';
    }
};