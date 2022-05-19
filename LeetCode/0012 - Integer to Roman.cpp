static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string intToRoman(int num)
    {
        unordered_map<int, string> dict = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
        vector<int> V = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans;
        
        for (int i = 0; i < V.size(); ++i)
        {
            while (num >= V[i])
            {
                ans += dict[V[i]];
                num -= V[i];
            }
        }
        
        return ans;
    }
};