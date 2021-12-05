static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int cnt = 0;
        int tmp = 0;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        
        for (auto& i : flowerbed)
        {
            tmp |= i;
            if (++cnt == 3 && !tmp) --n, cnt = 1;
            if (tmp) tmp = 0, cnt = 0;
        }
        
        return n <= 0;
    }
};