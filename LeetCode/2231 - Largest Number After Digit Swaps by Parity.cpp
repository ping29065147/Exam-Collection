static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int largestInteger(int num)
    {
        vector<int> n, n1, n2;
        int ans = 0;
        
        while(num)
        {
            ((num & 1) ? n1 : n2).push_back(num % 10);
            n.push_back(num % 10);
            num /= 10;
        }
        
        sort(n1.begin(), n1.end());
        sort(n2.begin(), n2.end());
        
        for (int i = 0; i < n.size(); ++i)
        {
            ans *= 10;
            auto& cur = (n[n.size() - i - 1] & 1) ? n1 : n2;
            ans += cur.back();
            cur.pop_back();
        }
        
        return ans;
    }
};