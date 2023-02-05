static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string decodeMessage(string key, string message)
    {
        unordered_map<char, char> M;
        char al = 'a';
        string res;
        
        for (auto& c : key)
            if (isalpha(c) && !isalpha(M[c]))
                M[c] = al++;
        
        for (auto& c : message)
            res += isalpha(c) ? M[c] : ' ';
        
        return res;
    }
};