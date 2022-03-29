static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        unordered_map<char, bool> M;
        stringstream ss(text);
        string str;
        int cnt = 0;
        
        for (auto& c : brokenLetters) M[c] = true;
        while(ss >> str)
        {
            for (auto& c : str) if (M[c])
            {
                --cnt;
                break;
            }
            ++cnt;
        }
        
        return cnt;
    }
};