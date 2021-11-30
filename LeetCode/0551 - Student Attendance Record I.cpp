static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool checkRecord(string s)
    {
        int a = 0, l = 0;
        
        for (auto& c : s)
        {
            if (c == 'A') ++a, l = 0;
            else if (c == 'L') ++l;
            else l = 0;
            
            if (a >= 2 || l >= 3) return false;
        }
        
        return true;
    }
};