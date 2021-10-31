static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ret(max(a.size(), b.size()) + 1, '0');
        
        for (int i = 0; i < a.size(); ++i) ret[i] = a[i];  
        for (int i = 0; i < b.size(); ++i) ret[i] += (b[i] - '0');      
        for (int i = 0; i < ret.size(); ++i) if (ret[i] >= '2')
        {
            ret[i] -= 2;
            ++ret[i + 1];
        }
        
        reverse(ret.begin(), ret.end());
        if (ret[0] == '0') ret.erase(ret.begin());
        return ret;
    }
};