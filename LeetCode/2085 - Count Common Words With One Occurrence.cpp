static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2)
    {
        int cnt = 0;
        unordered_map<string, int> M1, M2;
        
        for (auto& s : words1) ++M1[s];
        for (auto& s : words2) ++M2[s];
        for (auto& s : words2) 
            if (M1[s] == 1 && M2[s] == 1) 
                ++cnt;
        
        return cnt;
    }
};