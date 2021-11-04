static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> last;
        
        for (int i = 0; i <= rowIndex; ++i)
        {
            vector<int> tmp;
            
            for (int j = 0; j <= i; ++j)
            {
                if (!j || j == i) tmp.push_back(1);
                else tmp.push_back(last[j - 1] + last[j]);
            }
            
            last = tmp;
        }
        
        return last;
    }
};