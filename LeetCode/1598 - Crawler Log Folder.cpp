static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();


class Solution {
public:
    int minOperations(vector<string>& logs)
    {
        int cnt = 0;
        
        for (auto& s : logs)
        {
            if (s == "./") continue;
            else if (s == "../") { if (cnt) --cnt; }
            else ++cnt;
        }
        
        return cnt;
    }
};