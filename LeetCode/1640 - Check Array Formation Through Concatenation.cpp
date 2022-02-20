static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces)
    {
        unordered_map<int, int> M;
        
        for (int i = 0; i < pieces.size(); ++i) M[pieces[i][0]] = i;
        for (int i = 0; i < arr.size();)
        {
            if (!M.count(arr[i])) return false;
            
            auto n = pieces[M[arr[i]]];
            for (int j = 0; j < n.size(); ++j, ++i)
                if (arr[i] != n[j])
                    return false;
        }
        
        return true;
    }
};