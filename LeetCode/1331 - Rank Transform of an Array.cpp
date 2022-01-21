static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr)
    {
        set<int> S(arr.begin(), arr.end());
        vector<int> ret(arr.size());
        unordered_map<int, int> M;
        int cnt = 0;
        
        for (auto& i : S) M[i] = ++cnt;
        for (int i = 0; i < arr.size(); ++i) ret[i] = M[arr[i]];
        
        return ret;
    }
};