static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    string reformat(string s)
    {
        string q1, q2;
        string ret;
        
        for (auto& c : s)
        {
            if (isdigit(c)) q1 += c;
            else q2 += c;
        }
        
        if (q1.size() < q2.size()) swap(q1, q2);
        if (q1.size() > q2.size() + 1) return "";
        
        int i = 0, j = 0;
        while(j < q2.size())
        {
            ret += q1[i++];
            ret += q2[j++];
        }
        if (q1.size() - q2.size()) ret += q1[i];
        
        return ret;
    }
};