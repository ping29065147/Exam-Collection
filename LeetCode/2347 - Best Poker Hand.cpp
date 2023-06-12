static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits)
    {
        unordered_map<int, int> M1;
        unordered_map<char, int> M2;
        bool isPair = false;
        
        for (int i = 0; i < 5; ++i)
        {
            ++M1[ranks[i]];
            ++M2[suits[i]];
        } 

        for (auto& [i, j] : M2) if (j == 5) return "Flush";
        for (auto& [i, j] : M1)
        {
            if (j >= 3) return "Three of a Kind";
            else if (j == 2) isPair = true;
        }

        return isPair ? "Pair" : "High Card";
    }
};