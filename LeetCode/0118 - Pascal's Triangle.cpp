static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ret;
        
        for (int i = 0; i < numRows; ++i)
        {
            vector<int> tmp;
            
            for (int j = 0; j <= i; ++j)
            {
                if (!j || j == i) tmp.push_back(1);
                else tmp.push_back(ret.back()[j - 1] + ret.back()[j]);              
            }
            
            ret.push_back(tmp);
        }
        
        return ret;
    }
};