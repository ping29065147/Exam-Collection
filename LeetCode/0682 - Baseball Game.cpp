static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int calPoints(vector<string>& ops)
    {
        vector<int> ret;
        int cnt = 0;
        
        for (auto& op : ops)
        {
            if (op == "+") ret.push_back(ret[ret.size() - 2] + ret.back());
            else if (op == "D") ret.push_back(ret.back() * 2);
            else if (op == "C") ret.pop_back();
            else ret.push_back(stoi(op));
        }
        
        for (auto& i : ret) cnt += i;
        return cnt;
    }
};