static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second)
    {
        stringstream ss(text);
        vector<string> V, ret;
        string str;
        
        while(ss >> str) V.push_back(str);
        for (int i = 2; i < V.size(); ++i)
            if (V[i - 2] == first && V[i - 1] == second)
                ret.push_back(V[i]);
        
        return ret;
    }
};