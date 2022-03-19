static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numDifferentIntegers(string word)
    {
        for (auto& c : word) if (isalpha(c)) c = ' ';
        
        stringstream ss(word);
        unordered_set<string> S;
        string str;
        
        while(ss >> str)
        {
            while(!str.empty() && str[0] == '0') str.erase(str.begin());
            S.insert(str);
        }
        
        return S.size();
    }
};