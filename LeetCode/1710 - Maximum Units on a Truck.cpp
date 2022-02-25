static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        vector<pair<int, int>> V;
        int cnt = 0;
        
        for (auto & v : boxTypes) V.push_back({v[1], v[0]});
        sort(V.begin(), V.end(), greater<pair<int, int>>());
        
        for (auto& [i, j] : V)
        {
            while(truckSize && j)
            {
                cnt += i;
                --j;
                --truckSize;
            }
        }
        
        return cnt;
    }
};