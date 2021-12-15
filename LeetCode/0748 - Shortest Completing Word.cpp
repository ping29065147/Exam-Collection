static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words)
    {
        string ret;
        int sum = 0;
        unordered_map<char, int> M;
        
        for (auto& c : licensePlate) if (isalpha(c))
        {
            ++M[tolower(c)];
            ++sum;
        }
        for (auto& word : words)
        {
            int cnt = sum;
            unordered_map<char, int> tmp = M;
            
            for (auto& c : word) if (--tmp[c] >= 0) --cnt;
            if (!cnt && (ret.empty() || ret.size() > word.size())) ret = word;
        }
        
        return ret;
    }
};