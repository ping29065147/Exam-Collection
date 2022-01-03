static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order)
    {
        unordered_map<char, int> O;
        int cnt = 0;
        
        for (auto& c : order) O[c] = cnt++;
        
        for (int i = 1; i < words.size(); ++i)
        {           
            int j = 0;
            string s1 = words[i - 1];
            string s2 = words[i];
            
            if (s1 == s2) continue;
            
            for (; j < min(s1.size(), s2.size()); ++j)
            {
                if (O[s1[j]] > O[s2[j]]) return false;
                else if (O[s1[j]] < O[s2[j]]) break;
            }
            if (j == min(s1.size(), s2.size())) return s1.size() < s2.size();
        }
        
        return true;
    }
};