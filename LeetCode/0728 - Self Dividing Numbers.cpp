auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ret;
        
        for (; left <= right; ++left) if (isSDN(left)) ret.push_back(left);
        
        return ret;
    }
    
    bool isSDN(int num)
    {
        int cpy = num;
        
        while(cpy != 0)
        {
            int tmp = cpy % 10;
            if (!tmp) return false;
            if (num % tmp) return false;
            cpy /= 10;
        }
        
        return true;
    }
};