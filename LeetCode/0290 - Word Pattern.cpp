static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, int> M1;
        unordered_map<string, int> M2;
        stringstream ss(s);
        string tmp;
        int i = 0;
        
        while(ss >> tmp)
        {
            if (i == pattern.size() || M1[pattern[i]] != M2[tmp]) return false;
            M1[pattern[i]] = M2[tmp] = i + 1;
            ++i;
        }
        
        return i == pattern.size();
    }
};