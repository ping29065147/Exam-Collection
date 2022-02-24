static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string reformatNumber(string number)
    {
        string ret;
        int cnt = 0;
        
        for (auto& c : number)
        {
            if (c == ' ' || c == '-') continue;
            
            ret += c;
            if (++cnt % 3 == 0) ret += '-';
        }
        
        if (ret.back() == '-') ret.pop_back();
        if (cnt % 3 == 1) swap(ret[ret.size() - 2], ret[ret.size() - 3]);
        
        return ret;
    }
};