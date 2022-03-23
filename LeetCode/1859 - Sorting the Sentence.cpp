static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string sortSentence(string s)
    {
        stringstream ss(s);
        string str, ret;
        vector<string> V;
        
        while(ss >> str)
        {
            str = str.back() + str;
            str.pop_back();
            V.push_back(str);
        }
        sort(V.begin(), V.end());
        for (auto& i : V) ret += i.substr(1) + " ";
        ret.pop_back();
        
        return ret;
    }
};