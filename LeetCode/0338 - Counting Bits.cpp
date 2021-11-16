static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> countBits(int n)
    {
        vector<int> ret;
        
        for (int i = 0; i <= n; ++i)
        {
            int tmp = 0;
            int cpy = i;
            while(cpy != 0) tmp += cpy & 1, cpy >>= 1;
            ret.push_back(tmp);
        }
        
        return ret;
    }
};