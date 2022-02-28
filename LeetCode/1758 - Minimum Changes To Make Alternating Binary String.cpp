static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minOperations(string s)
    {
        int x = 0, cnt1 = 0, cnt2 = 0;
        
        for (auto& c : s) 
        {
            if (c == x + '0') ++cnt1;
            else ++cnt2;
            x ^= 1;
        }
        
        return min(cnt1, cnt2);
    }
};