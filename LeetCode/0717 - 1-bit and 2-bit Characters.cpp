static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits)
    {   
        int ret = 0;
        
        for (int i = 0; i < bits.size(); ++i)
        {
            if (bits[i] == 0) ret = 0;
            else ++i, ret = 1;
        }
        
        return ret == 0;
    }
};