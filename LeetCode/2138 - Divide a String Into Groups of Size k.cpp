static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> divideString(string s, int k, char fill)
    {
        vector<string> V;
        string str;
        
        for (auto& c : s)
        {
            str += c;
            if (str.size() == k) V.push_back(str), str = "";
        }
        
        if (!str.empty())
        {
            while(str.size() != k) str += fill;
            V.push_back(str);
        }        
         
        return V;
    }
};