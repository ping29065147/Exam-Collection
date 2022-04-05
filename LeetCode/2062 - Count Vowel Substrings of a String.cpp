static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countVowelSubstrings(string word)
    {
        int n = word.size();
        int cnt = 0;
        
        for (int i = 0; i < n; ++i)
            for (int j = 5; i + j <= n; ++j)
                if (is_vowel(word.substr(i, j)))
                    ++cnt;
        
        return cnt;                
    }
    
    bool is_vowel(string s)
    {
        set<int> S;
        string str = "aeiou";
        
        for (auto& c : s)
        {
            if (str.find(c) == string::npos) return false;
            S.insert(c);
        }
        
        return S.size() == 5;
    }
};