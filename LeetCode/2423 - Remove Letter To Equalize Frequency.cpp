static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool equalFrequency(string word)
    {
        unordered_map<char, int> M, N;

        for (auto& c : word) ++M[c];
        // 字母全相同(只有1種)或字母全不同(有n種)
        if (M.size() == 1 || M.size() == word.size()) return true;

        for (auto& [i, j]: M) ++N[j];
        // 字母的數量超過2種，例abbccc：1個a、2個b、3個c
        if (N.size() > 2) return false;

        for (auto& [i, j]: N)
        {
            // 存在1種字母數量為其他字母數量+1個
            if (j == 1 && (N.count(i - 1))) return true;
            // 存在1種字母數量只有1個
            else if (N.count(1) && N[1] == 1) return true;
        }

        return false;
    }
};