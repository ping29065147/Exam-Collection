static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int binaryGap(int n)
    {
        vector<int> V;
        int cnt = 0, Max = 0;
        
        for (int cnt = 0; n != 0; ++cnt, n /= 2) if (n % 2) V.push_back(cnt);      
        for (int i = 1; i < V.size(); ++i) Max = max(Max, V[i] - V[i - 1]);
        
        return Max;
    }
};