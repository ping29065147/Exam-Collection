static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        vector<int> ans(n, 0);
        
        for (int i = 0; i < n; ++i)
        {
            if (boxes[i] == '0') continue;
            for (int j = i - 1, cnt = 0; j >= 0; --j) ans[j] += ++cnt;
            for (int j = i + 1, cnt = 0; j < n; ++j) ans[j] += ++cnt; 
        }
        
        return ans;
    }
};