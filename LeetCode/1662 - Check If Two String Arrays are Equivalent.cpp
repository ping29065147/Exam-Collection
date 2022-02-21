static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
    {
        string str1, str2;
        
        for (auto& s : word1) str1 += s;
        for (auto& s : word2) str2 += s;
        
        return str1 == str2;
    }
};