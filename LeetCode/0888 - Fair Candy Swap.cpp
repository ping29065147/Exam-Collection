static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes)
    {
        unordered_set S(aliceSizes.begin(), aliceSizes.end());
        int sum = 0;
        
        for (auto& i : aliceSizes) sum += i;
        for (auto& i : bobSizes) sum -= i;
        sum /= 2;
        for (auto& i : bobSizes) if (S.count(i + sum)) return {i + sum, i};
        
        return {};
    }
};