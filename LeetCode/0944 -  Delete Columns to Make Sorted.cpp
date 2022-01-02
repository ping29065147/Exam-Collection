static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int minDeletionSize(vector<string>& strs)
    {
        int cnt = 0;
        char c;
        
        for (int i = 0; i < strs[0].size(); ++i)
        {
            c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j)
            {
                if (strs[j][i] < c) 
                {
                    ++cnt;
                    break;
                }
                c = strs[j][i];
            }
        }
        
        return cnt;
    }
};