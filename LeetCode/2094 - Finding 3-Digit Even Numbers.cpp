static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits)
    {
        vector<int> cnt(10, 0);
        vector<int> V;        
        
        for (auto& i : digits)
            ++cnt[i];
        
        for (int i = 1; i <= 9; ++i)
            for (int j = 0; j <= 9; ++j)
                for (int k = 0; k < 9; k += 2)
                    if (cnt[i] > 0 && cnt[j] > (i == j) && cnt[k] > (k == i) + (k == j))
                        V.push_back(i * 100 + j * 10 + k);
        
        return V;
    }
};