static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
    {
        vector<string> ret;
        unordered_map<string, pair<int, int>> M;
        int Min = INT_MAX;
        
        for (int i = 0; i < list1.size(); ++i)
        {
            ++M[list1[i]].first;
            M[list1[i]].second += i;
        }
        for (int i = 0; i < list2.size(); ++i)
        {
            ++M[list2[i]].first;
            M[list2[i]].second += i;
            if (M[list2[i]].first == 2) Min = min(Min, M[list2[i]].second);
        }
        
        for (auto& [i, j] : M) if (j.first == 2 && j.second == Min) ret.push_back(i);
        return ret;
    }
};