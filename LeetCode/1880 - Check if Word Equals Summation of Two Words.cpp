static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord)
    {
        int n1 = 0, n2 = 0, n3 = 0;
        
        for (auto& i : firstWord) n1 = (n1 * 10) + (i - 'a');
        for (auto& i : secondWord) n2 = (n2 * 10) + (i - 'a');
        for (auto& i : targetWord) n3 = (n3 * 10) + (i - 'a');
        
        return n1 + n2 == n3;
    }
};