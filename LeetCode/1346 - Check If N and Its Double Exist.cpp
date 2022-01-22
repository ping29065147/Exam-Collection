static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool checkIfExist(vector<int>& arr)
    {
        unordered_map<int, int> M;
        
        for (auto& i : arr)
        {
            if ((i % 2 == 0 && M[i / 2]) || M[i * 2]) return true;
            ++M[i];
        }
        
        return false;
    }
};