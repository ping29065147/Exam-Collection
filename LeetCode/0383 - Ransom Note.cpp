static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> M;
        
        for (auto& c : magazine) ++M[c];
        
        for (auto& c : ransomNote)
        {
            if (M[c] > 0) --M[c];
            else return false;
        }
        
        return true;
    }
};