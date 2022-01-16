static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices)
    {
        int ret = 0;
        vector<int> R(m, 0), C(n, 0);
        
        for (auto& i : indices)
        {
            ++R[i[0]];
            ++C[i[1]];
        }
        
        for (int i = 0; i < m; ++i)
			for (int j = 0; j < n ;++j)
				ret += (R[i] + C[j]) % 2;
        
        return ret;
    }
};